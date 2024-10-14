/* Copyright (C)
* 2017 - John Melton, G0ORX/N6LYT
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <https://www.gnu.org/licenses/>.
*
*/

#ifndef _TRANSMITTER_H
#define _TRANSMITTER_H

#include <gtk/gtk.h>

#define CTCSS_FREQUENCIES 38
extern double ctcss_frequencies[CTCSS_FREQUENCIES];

typedef struct _transmitter {
  int id;
  int dac;
  int fps;
  int displaying;
  int mic_sample_rate;
  int mic_dsp_rate;
  int iq_output_rate;
  int buffer_size;
  int dsp_size;
  int fft_size;
  int pixels;
  int samples;
  int output_samples;
  int ratio;
  double *mic_input_buffer;
  double *iq_output_buffer;

  float *pixel_samples;
  int display_panadapter;
  int display_waterfall;
  guint update_timer_id;
  GMutex display_mutex;
  int display_detector_mode;
  int display_average_mode;
  double display_average_time;

  int filter_low;
  int filter_high;
  int use_rx_filter;

  int alex_antenna;

  int width;
  int height;

  GtkWidget *dialog;
  GtkWidget *panel;
  GtkWidget *panadapter;

  int panadapter_low;
  int panadapter_high;
  int panadapter_step;

  cairo_surface_t *panadapter_surface;

  int local_microphone;
  gchar microphone_name[128];

  int out_of_band;
  guint out_of_band_timer_id;

  int twotone;
  int puresignal;
  int feedback;
  int auto_on;

  // PS 2.0 parameters
  double ps_ampdelay;
  int    ps_ints;
  int    ps_spi;
  int    ps_stbl;
  int    ps_map;
  int    ps_pin;
  double ps_ptol;
  double ps_moxdelay;
  double ps_loopdelay;
  int    ps_oneshot;

  int ctcss_enabled;
  int ctcss;

  int deviation;
  int pre_emphasize;

  double am_carrier_level;

  int attenuation;      // Attenuation in the RX ADC0 chain (!) if TX is active

  int drive;            // value of the drive slider
  int tune_use_drive;
  int tune_drive;

  int drive_level;      // amplitude (0-255) corresponding to "drive"
  int do_scale;         // apply TX iq scaling
  double drive_scale;   // additional TX iq scaling required
  double drive_iscal;   // inverse of drive_scale
  double mic_gain;

  int compressor;
  double compressor_level;

  double fwd;
  double rev;
  double alc;
  int    alcmode;
  double swr;
  int    swr_protection;
  double swr_alarm;

  int x;
  int y;

  int dialog_x;
  int dialog_y;

  int display_filled;

  double *cw_sig_rf;      // contains the CW RF envelope

  int cw_ramp_audio_len;  // ramp width in samples
  int cw_ramp_audio_ptr;
  int cw_ramp_rf_len;     // ramp width in samples
  int cw_ramp_rf_ptr;
  double *cw_ramp_audio;  // ramp for the side tone
  double *cw_ramp_rf;     // ramp for the RF signal
  GMutex cw_ramp_mutex;   // needed when changing the ramp width during TX

  //
  // Equalizer data
  //
  int    eq_enable;
  double eq_freq[11];  // frequency in Hz
  double eq_gain[11];  // gain in dB
  int    eq_tenband;   // four or ten channels

  //-------------------- add CFC function ---------------------------/
  int txcfc_pre_enable;         // pre CFC on/off
  int txcfc_post_enable;        // post CFC on/off
  double txcfc_EQfrq[10];       // frequency in Hz
  double txcfc_preEQlevel[10];  // pre-gain per EQ band in db
  double txcfc_postEQlevel[10]; // post-gain per EQ band in db
  double txcfc_preGain;         // overall CFC pre-gain in db
  double txcfc_postGain;        // overall CFC post-gain in db
  

  int LevAttack;
  int LevDecay;
  double LevGain;
  //-----------------------------------------------------------------/

} TRANSMITTER;

extern TRANSMITTER *tx_create_transmitter(int id, int width, int height);

void tx_create_dialog(TRANSMITTER *tx);
void tx_reconfigure(TRANSMITTER *tx, int width, int height);

//
// CW pulse shaper variables
//
extern int cw_key_up;
extern int cw_key_down;
extern int cw_not_ready;

extern void   cw_hold_key(int state);

extern void   tx_add_mic_sample(TRANSMITTER *tx, float mic_sample);
extern void   tx_add_ps_iq_samples(const TRANSMITTER *tx, double i_sample_0, double q_sample_0, double i_sample_1,
                                   double q_sample_1);

extern void   tx_close(const TRANSMITTER *tx);
extern void   tx_create_analyzer(const TRANSMITTER *tx);
extern double tx_get_alc(const TRANSMITTER *tx);
extern int    tx_get_pixels(TRANSMITTER *tx);
extern void   tx_off(const TRANSMITTER *tx);
extern void   tx_on(const TRANSMITTER *tx);

extern void   tx_ps_getinfo(const TRANSMITTER *tx, int *info);
extern double tx_ps_getmx(const TRANSMITTER *tx);
extern double tx_ps_getpk(const TRANSMITTER *tx);
extern void   tx_ps_mox(const TRANSMITTER *tx, int state);
extern void   tx_ps_onoff(TRANSMITTER *tx, int state);
extern void   tx_ps_reset(const TRANSMITTER *tx);
extern void   tx_ps_resume(const TRANSMITTER *tx);
extern void   tx_ps_set_sample_rate(const TRANSMITTER *tx, int rate);
extern void   tx_ps_setparams(const TRANSMITTER *tx);
extern void   tx_ps_setpk(const TRANSMITTER *tx, double pk);

extern void   tx_save_state(const TRANSMITTER *tx);

extern void   tx_set_am_carrier_level(const TRANSMITTER *tx);
extern void   tx_set_analyzer(const TRANSMITTER *tx);
extern void   tx_set_average(const TRANSMITTER *tx);
extern void   tx_set_bandpass(const TRANSMITTER *tx);
extern void   tx_set_compressor(const TRANSMITTER *tx);
extern void   tx_set_ctcss(const TRANSMITTER *tx);
extern void   tx_set_detector(const TRANSMITTER *tx);
extern void   tx_set_deviation(const TRANSMITTER *tx);
extern void   tx_set_displaying(TRANSMITTER *tx);
extern void   tx_set_equalizer(TRANSMITTER *tx);
//-------------------- add CFC function ---------------------------/
extern void   tx_set_cfc(TRANSMITTER *tx);
//-----------------------------------------------------------------/
extern void   tx_set_fft_size(const TRANSMITTER *tx);
extern void   tx_set_filter(TRANSMITTER *tx);
extern void   tx_set_framerate(TRANSMITTER *tx);
extern void   tx_set_mic_gain(const TRANSMITTER *tx);
extern void   tx_set_mode(TRANSMITTER* tx, int m);
extern void   tx_set_out_of_band(TRANSMITTER *tx);
extern void   tx_set_pre_emphasize(const TRANSMITTER *tx);
extern void   tx_set_ramps(TRANSMITTER *tx);
extern void   tx_set_singletone(const TRANSMITTER *tx, int state, double freq);
extern void   tx_set_twotone(TRANSMITTER *tx, int state);

#endif


