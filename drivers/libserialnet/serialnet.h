// (C) 2017 Embedded Computing Systems - Vienna's Institute of Technology
// Author: Thomas Lamprecht <tlamprecht@ecs.tuwien.ac.at>

#ifndef ___SERIALNET_H__
#define ___SERIALNET_H__

#include <stdint.h>

// --- STATE FLAGS ---
// internal sate, can be helpfull for your application to see if the device
// was initialised successfully, for example, or to show the device currents
// status in the GUI.
// State flags won't get cleared automatically, so if you rely on them,
// clear them manually (i.e. in their callbacks).
// But, the callbacks always get executed, if set up, even if you do not
// clear the state

// device found and it responded (do not touch if you are unsure)
#define SERIALNET_DEV_BOOTED 1
// network set up (do not touch if you are unsure)
#define SERIALNET_DEV_INITIALISED 2
// last command successfull (free to clear, after initialisation)
#define SERIALNET_RESPONSE_OK 4
// last command errorneous (free to clear, after initialisation)
#define SERIALNET_RESPONSE_ERR 8
// got data from another node (free to clear)
#define SERIALNET_GOT_DATA 16
// got an event notification (free to clear)
#define SERIALNET_GOT_EVENT 32

// our internal parser got in an undefined state
// shouldn't happen, a safe way out is to reset this module and/or mail the
// author with an reproducible test case
#define SERIALNET_PARSE_ERROR 64

// after finding the device, i.e. SERIALNET_DEV_BOOTED was set, we try retrying
// the initialization again, but if it fails still after 10 tries we stop
// completely and this flag gets set.
// This should only happen on a grave misconfiguration or the device/uart link
// misbehaving
#define SERIALNET_INIT_MAX_RETRIES 128


// --- INIT & GENERAL FUNCTIONS ---

// param description:
// * got_data_cb: a callback function which gets called on a successful data
//   reception with the src address, the data and its length and the broadcast
//   flag as arguments
// * node_role, the device role in the network. Can be 0 = coordinator, 1 = router,
//   2 = end device
// * node_addr: the nodes address must be 0 if role is 0, mustn't be 0 if role is
//   not 0. Use 0xFFFF for auto-stochastic address assignment by the network
//   bust be unique in network (if not 0xFFFF)
// * node_mac: 8 * 8 bit words which form the 64 bit MAC address, must be unique!
uint8_t serialnet_init(
        void (*got_data_cb)(uint16_t src_addr, const char *data, uint8_t data_length, uint8_t broadcast),
        uint8_t node_role,
        uint16_t node_addr,
        uint8_t node_mac[8]
    );


// IMPORTANT: schedule this once in a while to make everything work
void serialnet_dispatch(void);


// This function allows to set the base network parameters. Those parameter
// cannot be set while connected to a network. So either call
// serialnet_init(...) after setting them.  Or change those paramters manually with AT command
// after disabling autonetworking and leaving the network.
// * pan_id: unique 64 bit ID of the network, allows multiple networks on same
//   channel, default is: {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x20}
// * channel_mask: 32 bit channel mask defines frequency band to use, default
//   to a 2.4GHz one, i.e.: {0x00, 0x10, 0x00, 0x00}
//
// Note: you can use NULL for a parameter to left it unchanged!
void serialnet_set_base_network(uint8_t *pan_id, uint8_t *channel_mask);


// --- SEND FUNCTIONS ---

// NOTE: do *NOT* call send methods from ISRs

// Sends the data string to the specified address
// Returns 0 if it could not schedule the send to the UART stack
// Returns 1 if everything went as expected
uint8_t serialnet_send_data(uint16_t addr, const char *data);


// Broadcasts the data string to the specified address.
// This means all nodes in the network get the data, use with care!
// Returns 0 if it could not schedule the send to the UART stack
// Returns 1 if everything went as expected
uint8_t serialnet_broadcast_data(const char *data);


// This sends the string in `cmd` unmodified to the attached serial net module
// Use this to get info or modify settings for stuff not dooable with the
// libraries interface, check out the SerialNet specification and its AT
// commands.
uint8_t serialnet_send_raw_cmd(const char *cmd);

// --- STATE READ & CONTROL FUNCTIONS ---

// returns the current internal library state, usage example:
// uint8_t is_inited = (serialnet_state() & SERIALNET_DEV_INITALISED);
uint8_t serialnet_get_state(void);

// set the flag in the internal state
void serialnet_set_state(uint8_t flag);

// clear the flag in the internal state
void serialnet_clear_state(uint8_t flag);

// --- REGISTER CALLBACK FUNCTIONS ---

// In addition to the obligatory data callback set on serialnet_init we allow
// setting callbacks which got called when we receive an OK, ERROR,
// EVENT from the module.
// Note that the events are active only after initialising, i.e. when the
// SERIALNET_DEV_INITIALISED flag is set.
void serialnet_set_event_callback(void (*event_cb)(const char *event));

void serialnet_set_ok_callback(void (*got_ok_cb)(void));

void serialnet_set_error_callback(void (*got_err_cb)(void));

#endif
