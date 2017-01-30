// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// ** Copyright UCAR (c) 1992 - 2017
// ** University Corporation for Atmospheric Research(UCAR)
// ** National Center for Atmospheric Research(NCAR)
// ** Boulder, Colorado, USA
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
////////////////////////////////////////////
// Params.hh
//
// TDRP header file for 'Params' class.
//
// Code for program Metar2Symprod
//
// This header file has been automatically
// generated by TDRP, do not modify.
//
/////////////////////////////////////////////

/**
 *
 * @file Params.hh
 *
 * This class is automatically generated by the Table
 * Driven Runtime Parameters (TDRP) system
 *
 * @class Params
 *
 * @author automatically generated
 *
 */

#ifndef Params_hh
#define Params_hh

using namespace std;

#include <tdrp/tdrp.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>

// Class definition

class Params {

public:

  // enum typedefs

  typedef enum {
    DEBUG_OFF = 0,
    DEBUG_NORM = 1,
    DEBUG_VERBOSE = 2
  } debug_t;

  typedef enum {
    DISPLAY_TEMP_C = 0,
    DISPLAY_TEMP_F = 1,
    DISPLAY_TEMP_K = 2
  } display_temp_t;

  typedef enum {
    VERT_ALIGN_TOP = 1,
    VERT_ALIGN_CENTER = 2,
    VERT_ALIGN_BOTTOM = 3
  } vert_align_t;

  typedef enum {
    HORIZ_ALIGN_LEFT = 1,
    HORIZ_ALIGN_CENTER = 2,
    HORIZ_ALIGN_RIGHT = 3
  } horiz_align_t;

  typedef enum {
    CEILING_METERS = 0,
    CEILING_KM = 1,
    CEILING_FT = 2,
    CEILING_KFT = 3,
    CEILING_FL = 4
  } ceiling_units_t;

  typedef enum {
    WIND_MS = 0,
    WIND_KTS = 1,
    WIND_MPH = 2,
    WIND_KPH = 3
  } wind_units_t;

  typedef enum {
    VISIBILITY_METERS = 0,
    VISIBILITY_KM = 1,
    VISIBILITY_METERS_KM = 2,
    VISIBILITY_MILES = 3
  } visibility_units_t;

  typedef enum {
    VFR = 0,
    MVFR = 1,
    IFR = 2
  } flight_category_label_t;

  // struct typedefs

  typedef struct {
    float min_lat;
    float min_lon;
    float max_lat;
    float max_lon;
  } bounding_box_t;

  typedef struct {
    tdrp_bool_t require_temperature;
    tdrp_bool_t require_dewpoint;
    tdrp_bool_t require_wind_speed;
    tdrp_bool_t require_wind_direction;
    tdrp_bool_t require_pressure;
    tdrp_bool_t require_ceiling;
    tdrp_bool_t require_visibility;
    tdrp_bool_t require_rvr;
  } required_fields_t;

  typedef struct {
    tdrp_bool_t do_draw;
    char* color;
    char* background_color;
    tdrp_bool_t override_color_from_flight_cat;
    char* font_name;
    int font_size;
    int x_offset;
    int y_offset;
    vert_align_t vert_align;
    horiz_align_t horiz_align;
  } text_item_t;

  typedef struct {
    double min;
    double max;
    char* color;
  } wind_speed_color_t;

  typedef struct {
    flight_category_label_t label;
    char* color;
    float ceiling_threshold;
    float visibility_threshold;
  } flight_category_t;

  typedef struct {
    int x;
    int y;
  } stroked_icon_point_t;

  ///////////////////////////
  // Member functions
  //

  ////////////////////////////////////////////
  // Default constructor
  //

  Params ();

  ////////////////////////////////////////////
  // Copy constructor
  //

  Params (const Params&);

  ////////////////////////////////////////////
  // Destructor
  //

  ~Params ();

  ////////////////////////////////////////////
  // Assignment
  //

  void operator=(const Params&);

  ////////////////////////////////////////////
  // loadFromArgs()
  //
  // Loads up TDRP using the command line args.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   char **params_path_p:
  //     If this is non-NULL, it is set to point to the path
  //     of the params file used.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int loadFromArgs(int argc, char **argv,
                   char **override_list,
                   char **params_path_p,
                   bool defer_exit = false);

  bool exitDeferred() { return (_exitDeferred); }

  ////////////////////////////////////////////
  // loadApplyArgs()
  //
  // Loads up TDRP using the params path passed in, and applies
  // the command line args for printing and checking.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   const char *param_file_path: the parameter file to be read in
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int loadApplyArgs(const char *params_path,
                    int argc, char **argv,
                    char **override_list,
                    bool defer_exit = false);

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  //

  static bool isArgValid(const char *arg);

  ////////////////////////////////////////////
  // load()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to load
  // up more than one class for a single application. It is a
  // lower-level routine than loadFromArgs, and hence more
  // flexible, but the programmer must do more work.
  //
  //   const char *param_file_path: the parameter file to be read in.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int load(const char *param_file_path,
           char **override_list,
           int expand_env, int debug);

  ////////////////////////////////////////////
  // loadFromBuf()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to
  // load up more than one module for a single application,
  // using buffers which have been read from a specified source.
  //
  //   const char *param_source_str: a string which describes the
  //     source of the parameter information. It is used for
  //     error reporting only.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   const char *inbuf: the input buffer
  //
  //   int inlen: length of the input buffer
  //
  //   int start_line_num: the line number in the source which
  //     corresponds to the start of the buffer.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int loadFromBuf(const char *param_source_str,
                  char **override_list,
                  const char *inbuf, int inlen,
                  int start_line_num,
                  int expand_env, int debug);

  ////////////////////////////////////////////
  // loadDefaults()
  //
  // Loads up default params for a given class.
  //
  // See load() for more detailed info.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int loadDefaults(int expand_env);

  ////////////////////////////////////////////
  // sync()
  //
  // Syncs the user struct data back into the parameter table,
  // in preparation for printing.
  //
  // This function alters the table in a consistent manner.
  // Therefore it can be regarded as const.
  //

  void sync() const;

  ////////////////////////////////////////////
  // print()
  // 
  // Print params file
  //
  // The modes supported are:
  //
  //   PRINT_SHORT:   main comments only, no help or descriptions
  //                  structs and arrays on a single line
  //   PRINT_NORM:    short + descriptions and help
  //   PRINT_LONG:    norm  + arrays and structs expanded
  //   PRINT_VERBOSE: long  + private params included
  //

  void print(FILE *out, tdrp_print_mode_t mode = PRINT_NORM);

  ////////////////////////////////////////////
  // checkAllSet()
  //
  // Return TRUE if all set, FALSE if not.
  //
  // If out is non-NULL, prints out warning messages for those
  // parameters which are not set.
  //

  int checkAllSet(FILE *out);

  //////////////////////////////////////////////////////////////
  // checkIsSet()
  //
  // Return TRUE if parameter is set, FALSE if not.
  //
  //

  int checkIsSet(const char *param_name);

  ////////////////////////////////////////////
  // arrayRealloc()
  //
  // Realloc 1D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int arrayRealloc(const char *param_name,
                   int new_array_n);

  ////////////////////////////////////////////
  // array2DRealloc()
  //
  // Realloc 2D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int array2DRealloc(const char *param_name,
                     int new_array_n1,
                     int new_array_n2);

  ////////////////////////////////////////////
  // freeAll()
  //
  // Frees up all TDRP dynamic memory.
  //

  void freeAll(void);

  ////////////////////////////////////////////
  // usage()
  //
  // Prints out usage message for TDRP args as passed
  // in to loadFromArgs().
  //

  static void usage(ostream &out);

  ///////////////////////////
  // Data Members
  //

  char _start_; // start of data region
                // needed for zeroing out data
                // and computing offsets

  debug_t debug;

  char* instance;

  tdrp_bool_t no_threads;

  int port;

  int qmax;

  int max_clients;

  tdrp_bool_t useAcceptedStationsList;

  char* *_acceptedStations;
  int acceptedStations_n;

  tdrp_bool_t useRejectedStationsList;

  char* *_rejectedStations;
  int rejectedStations_n;

  tdrp_bool_t usePressureRange;

  double minStationPressure;

  double maxStationPressure;

  tdrp_bool_t useBoundingBox;

  bounding_box_t bounding_box;

  tdrp_bool_t decimate_spatially;

  int decimate_n_lat;

  int decimate_n_lon;

  char* *_decimate_required_stations;
  int decimate_required_stations_n;

  tdrp_bool_t check_for_required_fields;

  required_fields_t required_fields;

  tdrp_bool_t do_translation;

  display_temp_t display_temp;

  tdrp_bool_t plot_unscaled;

  text_item_t temperature_label;

  text_item_t dew_point_label;

  tdrp_bool_t pressure_as_3_digits;

  tdrp_bool_t temps_to_1_digit;

  tdrp_bool_t temps_to_int;

  text_item_t pressure_label;

  text_item_t current_weather_label;

  text_item_t current_weather_type;

  text_item_t wind_gust_label;

  text_item_t ceiling_label;

  ceiling_units_t ceiling_units;

  wind_units_t wind_units;

  text_item_t visibility_label;

  text_item_t humidity_label;

  visibility_units_t visibility_units;

  text_item_t precip_rate_label;

  text_item_t precip_accum_label;

  tdrp_bool_t precip_accum_specify_duration_limits;

  int precip_accum_min_duration_secs;

  int precip_accum_max_duration_secs;

  tdrp_bool_t precip_accum_include_duration_text;

  int precip_accum_line_spacing_pixels;

  int station_name_label_len;

  text_item_t station_name_label;

  text_item_t time_label;

  tdrp_bool_t draw_wind_barb;

  int station_posn_circle_radius;

  char* wind_barb_color;

  tdrp_bool_t override_wind_barb_color_from_flight_cat;

  tdrp_bool_t override_wind_barb_color_from_wind_speed;

  wind_speed_color_t *_wind_speed_colors;
  int wind_speed_colors_n;

  int wind_barb_line_width;

  int wind_barb_shaft_len;

  int wind_barb_tick_len;

  float wind_ticks_angle_to_shaft;

  tdrp_bool_t draw_flight_category;

  flight_category_t *_flight_category;
  int flight_category_n;

  int flight_category_circle_radius;

  char* color;

  char* background_color;

  tdrp_bool_t activate_hidden_text;

  char* hidden_text_font_name;

  int hidden_text_x_offset;

  int hidden_text_y_offset;

  int hidden_text_font_size;

  vert_align_t hidden_text_vert_align;

  horiz_align_t hidden_text_horiz_align;

  char* hidden_text_foreground_color;

  char* hidden_text_background_color;

  tdrp_bool_t add_raw_data_as_chunk;

  tdrp_bool_t render_missing_ceiling_icon;

  char* missing_ceiling_icon_color;

  int missing_ceiling_icon_line_width;

  stroked_icon_point_t *_missing_ceiling_icon;
  int missing_ceiling_icon_n;

  double missing_ceiling_icon_scale;

  char _end_; // end of data region
              // needed for zeroing out data

private:

  void _init();

  mutable TDRPtable _table[95];

  const char *_className;

  bool _exitDeferred;

};

#endif

