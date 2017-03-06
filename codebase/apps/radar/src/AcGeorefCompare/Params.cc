// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// ** Copyright UCAR (c) 1992 - 2017
// ** University Corporation for Atmospheric Research(UCAR)
// ** National Center for Atmospheric Research(NCAR)
// ** Boulder, Colorado, USA
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program AcGeorefCompare
//
// This file has been automatically
// generated by TDRP, do not modify.
//
/////////////////////////////////////////////

/**
 *
 * @file Params.cc
 *
 * @class Params
 *
 * This class is automatically generated by the Table
 * Driven Runtime Parameters (TDRP) system
 *
 * @note Source is automatically generated from
 *       paramdef file at compile time, do not modify
 *       since modifications will be overwritten.
 *
 *
 * @author Automatically generated
 *
 */
using namespace std;

#include "Params.hh"
#include <cstring>

  ////////////////////////////////////////////
  // Default constructor
  //

  Params::Params()

  {

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "Params";

    // initialize table

    _init();

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Copy constructor
  //

  Params::Params(const Params& source)

  {

    // sync the source object

    source.sync();

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "Params";

    // copy table

    tdrpCopyTable((TDRPtable *) source._table, _table);

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Destructor
  //

  Params::~Params()

  {

    // free up

    freeAll();

  }

  ////////////////////////////////////////////
  // Assignment
  //

  void Params::operator=(const Params& other)

  {

    // sync the other object

    other.sync();

    // free up any existing memory

    freeAll();

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // copy table

    tdrpCopyTable((TDRPtable *) other._table, _table);

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = other._exitDeferred;

  }

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

  int Params::loadFromArgs(int argc, char **argv,
                           char **override_list,
                           char **params_path_p,
                           bool defer_exit)
  {
    int exit_deferred;
    if (_tdrpLoadFromArgs(argc, argv,
                          _table, &_start_,
                          override_list, params_path_p,
                          _className,
                          defer_exit, &exit_deferred)) {
      return (-1);
    } else {
      if (exit_deferred) {
        _exitDeferred = true;
      }
      return (0);
    }
  }

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

  int Params::loadApplyArgs(const char *params_path,
                            int argc, char **argv,
                            char **override_list,
                            bool defer_exit)
  {
    int exit_deferred;
    if (tdrpLoadApplyArgs(params_path, argc, argv,
                          _table, &_start_,
                          override_list,
                          _className,
                          defer_exit, &exit_deferred)) {
      return (-1);
    } else {
      if (exit_deferred) {
        _exitDeferred = true;
      }
      return (0);
    }
  }

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  //

  bool Params::isArgValid(const char *arg)
  {
    return (tdrpIsArgValid(arg));
  }

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

  int Params::load(const char *param_file_path,
                   char **override_list,
                   int expand_env, int debug)
  {
    if (tdrpLoad(param_file_path,
                 _table, &_start_,
                 override_list,
                 expand_env, debug)) {
      return (-1);
    } else {
      return (0);
    }
  }

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

  int Params::loadFromBuf(const char *param_source_str,
                          char **override_list,
                          const char *inbuf, int inlen,
                          int start_line_num,
                          int expand_env, int debug)
  {
    if (tdrpLoadFromBuf(param_source_str,
                        _table, &_start_,
                        override_list,
                        inbuf, inlen, start_line_num,
                        expand_env, debug)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadDefaults()
  //
  // Loads up default params for a given class.
  //
  // See load() for more detailed info.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadDefaults(int expand_env)
  {
    if (tdrpLoad(NULL,
                 _table, &_start_,
                 NULL, expand_env, FALSE)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // sync()
  //
  // Syncs the user struct data back into the parameter table,
  // in preparation for printing.
  //
  // This function alters the table in a consistent manner.
  // Therefore it can be regarded as const.
  //

  void Params::sync(void) const
  {
    tdrpUser2Table(_table, (char *) &_start_);
  }

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

  void Params::print(FILE *out, tdrp_print_mode_t mode)
  {
    tdrpPrint(out, _table, _className, mode);
  }

  ////////////////////////////////////////////
  // checkAllSet()
  //
  // Return TRUE if all set, FALSE if not.
  //
  // If out is non-NULL, prints out warning messages for those
  // parameters which are not set.
  //

  int Params::checkAllSet(FILE *out)
  {
    return (tdrpCheckAllSet(out, _table, &_start_));
  }

  //////////////////////////////////////////////////////////////
  // checkIsSet()
  //
  // Return TRUE if parameter is set, FALSE if not.
  //
  //

  int Params::checkIsSet(const char *paramName)
  {
    return (tdrpCheckIsSet(paramName, _table, &_start_));
  }

  ////////////////////////////////////////////
  // freeAll()
  //
  // Frees up all TDRP dynamic memory.
  //

  void Params::freeAll(void)
  {
    tdrpFreeAll(_table, &_start_);
  }

  ////////////////////////////////////////////
  // usage()
  //
  // Prints out usage message for TDRP args as passed
  // in to loadFromArgs().
  //

  void Params::usage(ostream &out)
  {
    out << "TDRP args: [options as below]\n"
        << "   [ -params/--params path ] specify params file path\n"
        << "   [ -check_params/--check_params] check which params are not set\n"
        << "   [ -print_params/--print_params [mode]] print parameters\n"
        << "     using following modes, default mode is 'norm'\n"
        << "       short:   main comments only, no help or descr\n"
        << "                structs and arrays on a single line\n"
        << "       norm:    short + descriptions and help\n"
        << "       long:    norm  + arrays and structs expanded\n"
        << "       verbose: long  + private params included\n"
        << "       short_expand:   short with env vars expanded\n"
        << "       norm_expand:    norm with env vars expanded\n"
        << "       long_expand:    long with env vars expanded\n"
        << "       verbose_expand: verbose with env vars expanded\n"
        << "   [ -tdrp_debug] debugging prints for tdrp\n"
        << "   [ -tdrp_usage] print this usage\n";
  }

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

  int Params::arrayRealloc(const char *param_name, int new_array_n)
  {
    if (tdrpArrayRealloc(_table, &_start_,
                         param_name, new_array_n)) {
      return (-1);
    } else {
      return (0);
    }
  }

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

  int Params::array2DRealloc(const char *param_name,
                             int new_array_n1,
                             int new_array_n2)
  {
    if (tdrpArray2DRealloc(_table, &_start_, param_name,
                           new_array_n1, new_array_n2)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // _init()
  //
  // Class table initialization function.
  //
  //

  void Params::_init()

  {

    TDRPtable *tt = _table;

    // Parameter 'Comment 0'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 0");
    tt->comment_hdr = tdrpStrDup("AcGeorefCompare reads multiple ac georef data sets from SPDB and compares them. It is designed to compare the NCAR GV INS with the HCR Gmigits unit.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("DEBUGGING AND PROCESS CONTROL");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'debug'
    // ctype is '_debug_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("debug");
    tt->descr = tdrpStrDup("Debug option");
    tt->help = tdrpStrDup("If set, debug messages will be printed appropriately");
    tt->val_offset = (char *) &debug - &_start_;
    tt->enum_def.name = tdrpStrDup("debug_t");
    tt->enum_def.nfields = 4;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("DEBUG_OFF");
      tt->enum_def.fields[0].val = DEBUG_OFF;
      tt->enum_def.fields[1].name = tdrpStrDup("DEBUG_NORM");
      tt->enum_def.fields[1].val = DEBUG_NORM;
      tt->enum_def.fields[2].name = tdrpStrDup("DEBUG_VERBOSE");
      tt->enum_def.fields[2].val = DEBUG_VERBOSE;
      tt->enum_def.fields[3].name = tdrpStrDup("DEBUG_EXTRA");
      tt->enum_def.fields[3].val = DEBUG_EXTRA;
    tt->single_val.e = DEBUG_OFF;
    tt++;
    
    // Parameter 'reg_with_procmap'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("reg_with_procmap");
    tt->descr = tdrpStrDup("Register with procmap.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &reg_with_procmap - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'instance'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("instance");
    tt->descr = tdrpStrDup("Process instance");
    tt->help = tdrpStrDup("Used for registration with procmap.");
    tt->val_offset = (char *) &instance - &_start_;
    tt->single_val.s = tdrpStrDup("test");
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("OPERATIONS MODE");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'product_type'
    // ctype is '_product_type_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("product_type");
    tt->descr = tdrpStrDup("Type of product that is produced.");
    tt->help = tdrpStrDup("TIME_SERIES_TABLE: produced a text table, one line per primary observation. Results are written to stdout. Each line contains data from both data sets, along with differences between them. The start and end times are specified on the command line.\n\nSINGLE_PERIOD_ARCHIVE: analyze a single specified time period, in archive mode. Print the results in for that single period to stdout. The start time is specified on the command line.\n\nSINGLE_PERIOD_REALTIME: in realtime mode, analyze single time periods. Print the results in for that single period to stdout. Sleep and repeat.");
    tt->val_offset = (char *) &product_type - &_start_;
    tt->enum_def.name = tdrpStrDup("product_type_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("TIME_SERIES_TABLE");
      tt->enum_def.fields[0].val = TIME_SERIES_TABLE;
      tt->enum_def.fields[1].name = tdrpStrDup("SINGLE_PERIOD_ARCHIVE");
      tt->enum_def.fields[1].val = SINGLE_PERIOD_ARCHIVE;
      tt->enum_def.fields[2].name = tdrpStrDup("SINGLE_PERIOD_REALTIME");
      tt->enum_def.fields[2].val = SINGLE_PERIOD_REALTIME;
    tt->single_val.e = TIME_SERIES_TABLE;
    tt++;
    
    // Parameter 'start_time'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("start_time");
    tt->descr = tdrpStrDup("Start time in yyyy mm dd hh mm ss");
    tt->help = tdrpStrDup("Applies to TIME_SERIES_TABLE and SINGLE_PERIOD_ARCHIVE product types.");
    tt->val_offset = (char *) &start_time - &_start_;
    tt->single_val.s = tdrpStrDup("2016 09 16 16 00 00");
    tt++;
    
    // Parameter 'end_time'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("end_time");
    tt->descr = tdrpStrDup("End time in yyyy mm dd hh mm ss");
    tt->help = tdrpStrDup("Applies to TIME_SERIES_TABLE product type.");
    tt->val_offset = (char *) &end_time - &_start_;
    tt->single_val.s = tdrpStrDup("2016 09 16 16 00 00");
    tt++;
    
    // Parameter 'single_period_secs'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("single_period_secs");
    tt->descr = tdrpStrDup("Period for analysis (secs).");
    tt->help = tdrpStrDup("Mean values are computed over this period. Applies to SINGLE_PERIOD_REALTIME and SINGLE_PERIOD_ARCHIVE product types.");
    tt->val_offset = (char *) &single_period_secs - &_start_;
    tt->single_val.d = 2;
    tt++;
    
    // Parameter 'realtime_sleep_secs'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("realtime_sleep_secs");
    tt->descr = tdrpStrDup("Sleep time in realtime mode (secs).");
    tt->help = tdrpStrDup("The program repeatedly, sleeping between data retrieval. The end time is the current time, and the start time is the end time minus single_period_secs.");
    tt->val_offset = (char *) &realtime_sleep_secs - &_start_;
    tt->single_val.d = 1;
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("DATA INPUT");
    tt->comment_text = tdrpStrDup("We specify a primary and secondary data set. The primary set is read in first, and then data from the secondary data set is matched in time to the entries in the primary.");
    tt++;
    
    // Parameter 'primary_spdb_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("primary_spdb_url");
    tt->descr = tdrpStrDup("SPDB url for primary data set.");
    tt->help = tdrpStrDup("Can take the form of a local directory path, or a full url of the form:\n\n\t'spdbp:://hostname::dir_path'\n\nIf the dir_path starts with '.' or '/', it specifies a relative or absolute path respectively. If not, it specifies a path relative to '$DATA_DIR'.");
    tt->val_offset = (char *) &primary_spdb_url - &_start_;
    tt->single_val.s = tdrpStrDup("/tmp/spdb/ac_georef/raf_1hz");
    tt++;
    
    // Parameter 'secondary_spdb_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("secondary_spdb_url");
    tt->descr = tdrpStrDup("SPDB url for secondary data set.");
    tt->help = tdrpStrDup("Can take the form of a local directory path, or a full url of the form:\n\n\t'spdbp:://hostname::dir_path'\n\nIf the dir_path starts with '.' or '/', it specifies a relative or absolute path respecively. If not, it specifies a path relative to '$DATA_DIR'.");
    tt->val_offset = (char *) &secondary_spdb_url - &_start_;
    tt->single_val.s = tdrpStrDup("/tmp/spdb/ac_georef/cfradial_10hz");
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("DATA ANALYSIS");
    tt->comment_text = tdrpStrDup("Data is written to stdout in ASCII column format.");
    tt++;
    
    // Parameter 'primary_frequency_hz'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("primary_frequency_hz");
    tt->descr = tdrpStrDup("Frequency of primary data to be used in the analysis.");
    tt->help = tdrpStrDup("If the data in the primary data set is more frequent than this, we trim it down to this frequency.");
    tt->val_offset = (char *) &primary_frequency_hz - &_start_;
    tt->single_val.d = 1;
    tt++;
    
    // Parameter 'time_block_secs'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("time_block_secs");
    tt->descr = tdrpStrDup("Length of data time blocks to be read in (secs).");
    tt->help = tdrpStrDup("The data is read in blocks of this length, to control memory usage for large data sets.");
    tt->val_offset = (char *) &time_block_secs - &_start_;
    tt->single_val.i = 60;
    tt++;
    
    // Parameter 'max_time_diff_secs'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("max_time_diff_secs");
    tt->descr = tdrpStrDup("Maximum time difference for valid pair (secs).");
    tt->help = tdrpStrDup("This is the max valid time difference between a primary observation and secondary observation.");
    tt->val_offset = (char *) &max_time_diff_secs - &_start_;
    tt->single_val.d = 0.5;
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("AIRCRAFT WEIGHT CALCULATIONS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'fuel_burn_rate_initial_climb'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("fuel_burn_rate_initial_climb");
    tt->descr = tdrpStrDup("Fuel burn rate in initial climb (lb/hr).");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &fuel_burn_rate_initial_climb - &_start_;
    tt->single_val.d = 11500;
    tt++;
    
    // Parameter 'mean_fuel_burn_rate_cruise'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("mean_fuel_burn_rate_cruise");
    tt->descr = tdrpStrDup("Mean Fuel burn rate in cruise after the initial climb (lb/hr).");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &mean_fuel_burn_rate_cruise - &_start_;
    tt->single_val.d = 3500;
    tt++;
    
    // Parameter 'takeoff_weight_lbs'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("takeoff_weight_lbs");
    tt->descr = tdrpStrDup("Aircraft takeoff weight (lb).");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &takeoff_weight_lbs - &_start_;
    tt->single_val.d = 88000;
    tt++;
    
    // Parameter 'top_of_climb_altitude_ft'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("top_of_climb_altitude_ft");
    tt->descr = tdrpStrDup("Target top of climb altitude (ft).");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &top_of_climb_altitude_ft - &_start_;
    tt->single_val.d = 20000;
    tt++;
    
    // Parameter 'Comment 6'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 6");
    tt->comment_hdr = tdrpStrDup("TIME SERIES TABLE DETAILS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'print_commented_header'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("print_commented_header");
    tt->descr = tdrpStrDup("If true, write a commented header at the start of the output.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &print_commented_header - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'comment_character'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("comment_character");
    tt->descr = tdrpStrDup("Character at start of comment lines.");
    tt->help = tdrpStrDup("Each comment line will be start with this character.");
    tt->val_offset = (char *) &comment_character - &_start_;
    tt->single_val.s = tdrpStrDup("#");
    tt++;
    
    // Parameter 'column_delimiter'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("column_delimiter");
    tt->descr = tdrpStrDup("Delimiter between columns.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &column_delimiter - &_start_;
    tt->single_val.s = tdrpStrDup(" ");
    tt++;
    
    // Parameter 'Comment 7'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 7");
    tt->comment_hdr = tdrpStrDup("SINGLE PERIOD OUTPUT DETAILS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'print_single_period_stats'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("print_single_period_stats");
    tt->descr = tdrpStrDup("If true, write the single period statistics to stdout.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &print_single_period_stats - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'primary_label'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("primary_label");
    tt->descr = tdrpStrDup("Label for primary column in printout.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &primary_label - &_start_;
    tt->single_val.s = tdrpStrDup("primary");
    tt++;
    
    // Parameter 'secondary_label'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("secondary_label");
    tt->descr = tdrpStrDup("Label for secondary column in printout.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &secondary_label - &_start_;
    tt->single_val.s = tdrpStrDup("secondary");
    tt++;
    
    // Parameter 'print_primary_custom_variables'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("print_primary_custom_variables");
    tt->descr = tdrpStrDup("If true, write the custom variables for primary data set.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &print_primary_custom_variables - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'primary_custom_labels'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("primary_custom_labels");
    tt->descr = tdrpStrDup("Labels for primary custom variables.");
    tt->help = tdrpStrDup("If the label is left empty, the variable is not printed.");
    tt->array_offset = (char *) &_primary_custom_labels - &_start_;
    tt->array_n_offset = (char *) &primary_custom_labels_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = TRUE;
    tt->array_elem_size = sizeof(char*);
    tt->array_n = 10;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].s = tdrpStrDup("custom0");
      tt->array_vals[1].s = tdrpStrDup("custom1");
      tt->array_vals[2].s = tdrpStrDup("custom2");
      tt->array_vals[3].s = tdrpStrDup("custom3");
      tt->array_vals[4].s = tdrpStrDup("custom4");
      tt->array_vals[5].s = tdrpStrDup("custom5");
      tt->array_vals[6].s = tdrpStrDup("custom6");
      tt->array_vals[7].s = tdrpStrDup("custom7");
      tt->array_vals[8].s = tdrpStrDup("custom8");
      tt->array_vals[9].s = tdrpStrDup("custom9");
    tt++;
    
    // Parameter 'print_secondary_custom_variables'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("print_secondary_custom_variables");
    tt->descr = tdrpStrDup("If true, write the custom variables for secondary data set.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &print_secondary_custom_variables - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'secondary_custom_labels'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("secondary_custom_labels");
    tt->descr = tdrpStrDup("Labels for secondary custom variables.");
    tt->help = tdrpStrDup("If the label is left empty, the variable is not printed.");
    tt->array_offset = (char *) &_secondary_custom_labels - &_start_;
    tt->array_n_offset = (char *) &secondary_custom_labels_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = TRUE;
    tt->array_elem_size = sizeof(char*);
    tt->array_n = 10;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].s = tdrpStrDup("custom0");
      tt->array_vals[1].s = tdrpStrDup("custom1");
      tt->array_vals[2].s = tdrpStrDup("custom2");
      tt->array_vals[3].s = tdrpStrDup("custom3");
      tt->array_vals[4].s = tdrpStrDup("custom4");
      tt->array_vals[5].s = tdrpStrDup("custom5");
      tt->array_vals[6].s = tdrpStrDup("custom6");
      tt->array_vals[7].s = tdrpStrDup("custom7");
      tt->array_vals[8].s = tdrpStrDup("custom8");
      tt->array_vals[9].s = tdrpStrDup("custom9");
    tt++;
    
    // Parameter 'print_surface_velocity_stats'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("print_surface_velocity_stats");
    tt->descr = tdrpStrDup("If true, print the surface velocity stats for HCR.");
    tt->help = tdrpStrDup("The estimated pitch and roll angle errors will also be printed.");
    tt->val_offset = (char *) &print_surface_velocity_stats - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'surface_velocity_custom_index'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("surface_velocity_custom_index");
    tt->descr = tdrpStrDup("Index of surface velocity in the custom variables.");
    tt->help = tdrpStrDup("The surface velocity will be in the secondary data set.");
    tt->val_offset = (char *) &surface_velocity_custom_index - &_start_;
    tt->single_val.i = 1;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
