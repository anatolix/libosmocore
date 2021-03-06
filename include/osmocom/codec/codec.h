#pragma once

#include <stdint.h>
#include <stdbool.h>

#include <osmocom/core/utils.h>

extern const uint16_t gsm610_bitorder[];	/* FR */
extern const uint16_t gsm620_unvoiced_bitorder[]; /* HR unvoiced */
extern const uint16_t gsm620_voiced_bitorder[];   /* HR voiced */
extern const uint16_t gsm660_bitorder[];	/* EFR */

extern const uint16_t gsm690_12_2_bitorder[];	/* AMR 12.2  kbits */
extern const uint16_t gsm690_10_2_bitorder[];	/* AMR 10.2  kbits */
extern const uint16_t gsm690_7_95_bitorder[];	/* AMR  7.95 kbits */
extern const uint16_t gsm690_7_4_bitorder[];	/* AMR  7.4  kbits */
extern const uint16_t gsm690_6_7_bitorder[];	/* AMR  6.7  kbits */
extern const uint16_t gsm690_5_9_bitorder[];	/* AMR  5.9  kbits */
extern const uint16_t gsm690_5_15_bitorder[];	/* AMR  5.15 kbits */
extern const uint16_t gsm690_4_75_bitorder[];	/* AMR  4.75 kbits */

extern const struct value_string osmo_amr_type_names[];

enum osmo_amr_type {
       AMR_4_75 = 0,
       AMR_5_15 = 1,
       AMR_5_90 = 2,
       AMR_6_70 = 3,
       AMR_7_40 = 4,
       AMR_7_95 = 5,
       AMR_10_2 = 6,
       AMR_12_2 = 7,
       AMR_SID = 8,
       AMR_GSM_EFR_SID = 9,
       AMR_TDMA_EFR_SID = 10,
       AMR_PDC_EFR_SID = 11,
       AMR_NO_DATA = 15,
};

enum osmo_amr_quality {
       AMR_BAD = 0,
       AMR_GOOD = 1
};

bool osmo_fr_check_sid(uint8_t *rtp_payload, size_t payload_len);
bool osmo_hr_check_sid(uint8_t *rtp_payload, size_t payload_len);
int osmo_amr_rtp_enc(uint8_t *payload, uint8_t cmr, enum osmo_amr_type ft,
		     enum osmo_amr_quality bfi);
int osmo_amr_rtp_dec(const uint8_t *payload, int payload_len, uint8_t *cmr,
		     int8_t *cmi, enum osmo_amr_type *ft,
		     enum osmo_amr_quality *bfi, int8_t *sti);
