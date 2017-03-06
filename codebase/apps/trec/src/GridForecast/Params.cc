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
// Code for program GridForecast
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
    tt->comment_hdr = tdrpStrDup("GridForecast makes a forecast using a gridded field, such as radar reflectivity, and a field of U/V velocity values. Input and output data are both in MDV format.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'debug'
    // ctype is '_debug_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("debug");
    tt->descr = tdrpStrDup("Debug option");
    tt->help = tdrpStrDup("If set, debug messages will be printed with the appropriate level of detail.");
    tt->val_offset = (char *) &debug - &_start_;
    tt->enum_def.name = tdrpStrDup("debug_t");
    tt->enum_def.nfields = 4;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("DEBUG_OFF");
      tt->enum_def.fields[0].val = DEBUG_OFF;
      tt->enum_def.fields[1].name = tdrpStrDup("DEBUG_WARNINGS");
      tt->enum_def.fields[1].val = DEBUG_WARNINGS;
      tt->enum_def.fields[2].name = tdrpStrDup("DEBUG_NORM");
      tt->enum_def.fields[2].val = DEBUG_NORM;
      tt->enum_def.fields[3].name = tdrpStrDup("DEBUG_VERBOSE");
      tt->enum_def.fields[3].val = DEBUG_VERBOSE;
    tt->single_val.e = DEBUG_OFF;
    tt++;
    
    // Parameter 'instance'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("instance");
    tt->descr = tdrpStrDup("Process instance");
    tt->help = tdrpStrDup("Used for registration with procmap.");
    tt->val_offset = (char *) &instance - &_start_;
    tt->single_val.s = tdrpStrDup("Test");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("");
    tt->comment_text = tdrpStrDup("Operational mode");
    tt++;
    
    // Parameter 'mode'
    // ctype is '_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("mode");
    tt->descr = tdrpStrDup("Operation mode");
    tt->help = tdrpStrDup("In REALTIME mode, the analysis is performed for each volume scan as it becomes available. Triggering off motion file\n In SPEC_FCAST_REALTIME mode, the program waits for a new input file that is a forecast file with the specified forecast lead time.\n In ARCHIVE mode, the file list is obtained from the command line.\n In LATEST_DATA mode, the program waits for new data from the MDV location specified by the latest_data_trigger parameter.\n In TIME_LIST mode, the program operates on archive data as specified in the time_list_trigger parameter.\n In MULTIPLE_URL mode, the program will not run until data is available for all of the given URLs. This is a realtime mode. The parameters for this mode are given in the multiple_url_trigger.");
    tt->val_offset = (char *) &mode - &_start_;
    tt->enum_def.name = tdrpStrDup("mode_t");
    tt->enum_def.nfields = 6;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("ARCHIVE");
      tt->enum_def.fields[0].val = ARCHIVE;
      tt->enum_def.fields[1].name = tdrpStrDup("REALTIME");
      tt->enum_def.fields[1].val = REALTIME;
      tt->enum_def.fields[2].name = tdrpStrDup("SPEC_FCAST_REALTIME");
      tt->enum_def.fields[2].val = SPEC_FCAST_REALTIME;
      tt->enum_def.fields[3].name = tdrpStrDup("LATEST_DATA");
      tt->enum_def.fields[3].val = LATEST_DATA;
      tt->enum_def.fields[4].name = tdrpStrDup("TIME_LIST");
      tt->enum_def.fields[4].val = TIME_LIST;
      tt->enum_def.fields[5].name = tdrpStrDup("MULTIPLE_URL");
      tt->enum_def.fields[5].val = MULTIPLE_URL;
    tt->single_val.e = ARCHIVE;
    tt++;
    
    // Parameter 'max_realtime_valid_age'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("max_realtime_valid_age");
    tt->descr = tdrpStrDup("Max age of input data");
    tt->help = tdrpStrDup("For realtime only - max age of input data for it to be valid");
    tt->val_offset = (char *) &max_realtime_valid_age - &_start_;
    tt->has_min = TRUE;
    tt->min_val.l = 0;
    tt->single_val.l = 300;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("PROCESS TRIGGERING PARAMETERS");
    tt->comment_text = tdrpStrDup("Parameters describing the process triggering.");
    tt++;
    
    // Parameter 'latest_data_trigger'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("latest_data_trigger");
    tt->descr = tdrpStrDup("URL for triggering in latest data mode");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &latest_data_trigger - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://localhost::mdv/derived_ruc");
    tt++;
    
    // Parameter 'time_list_trigger'
    // ctype is '_time_list_trigger_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("time_list_trigger");
    tt->descr = tdrpStrDup("Trigger information used when using the TIME_LIST trigger");
    tt->help = tdrpStrDup("url specifies the triggering url.\nstart_time specifies the archive start time in any format recognized by the DateTime class.\nend_time specifies the archive end time in any format recognized by the DateTime class.");
    tt->val_offset = (char *) &time_list_trigger - &_start_;
    tt->struct_def.name = tdrpStrDup("time_list_trigger_t");
    tt->struct_def.nfields = 3;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("url");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &time_list_trigger.url - (char *) &time_list_trigger;
      tt->struct_def.fields[1].ftype = tdrpStrDup("string");
      tt->struct_def.fields[1].fname = tdrpStrDup("start_time");
      tt->struct_def.fields[1].ptype = STRING_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &time_list_trigger.start_time - (char *) &time_list_trigger;
      tt->struct_def.fields[2].ftype = tdrpStrDup("string");
      tt->struct_def.fields[2].fname = tdrpStrDup("end_time");
      tt->struct_def.fields[2].ptype = STRING_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &time_list_trigger.end_time - (char *) &time_list_trigger;
    tt->n_struct_vals = 3;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup("mdvp:://localhost::mdv/derived_ruc");
      tt->struct_vals[1].s = tdrpStrDup("2001/1/1 00:00:00");
      tt->struct_vals[2].s = tdrpStrDup("2002/1/2 00:00:00");
    tt++;
    
    // Parameter 'multiple_url_trigger'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("multiple_url_trigger");
    tt->descr = tdrpStrDup("List of URLs for triggering in latest data mode");
    tt->help = tdrpStrDup("");
    tt->array_offset = (char *) &_multiple_url_trigger - &_start_;
    tt->array_n_offset = (char *) &multiple_url_trigger_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(char*);
    tt->array_n = 1;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].s = tdrpStrDup("mdvp:://localhost::mdv/derived_ruc");
    tt++;
    
    // Parameter 'fcast_lead_time'
    // ctype is '_fcast_lead_time_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("fcast_lead_time");
    tt->descr = tdrpStrDup("Forecast lead time information for forecast files to be processed.");
    tt->help = tdrpStrDup("Used only if mode is set to SPEC_FCAST_REALTIME.");
    tt->val_offset = (char *) &fcast_lead_time - &_start_;
    tt->struct_def.name = tdrpStrDup("fcast_lead_time_t");
    tt->struct_def.nfields = 2;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("int");
      tt->struct_def.fields[0].fname = tdrpStrDup("lead_time_secs");
      tt->struct_def.fields[0].ptype = INT_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &fcast_lead_time.lead_time_secs - (char *) &fcast_lead_time;
      tt->struct_def.fields[1].ftype = tdrpStrDup("boolean");
      tt->struct_def.fields[1].fname = tdrpStrDup("use_gen_time");
      tt->struct_def.fields[1].ptype = BOOL_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &fcast_lead_time.use_gen_time - (char *) &fcast_lead_time;
    tt->n_struct_vals = 2;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].i = 0;
      tt->struct_vals[1].b = pFALSE;
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("");
    tt->comment_text = tdrpStrDup("Motion data");
    tt++;
    
    // Parameter 'motion_grid_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("motion_grid_url");
    tt->descr = tdrpStrDup("URL for grid files for U and V motion data.");
    tt->help = tdrpStrDup("The program triggers off files in this directory. It matches up an image file with the motion file and produces a forecast for the image.");
    tt->val_offset = (char *) &motion_grid_url - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://localhost::directory");
    tt++;
    
    // Parameter 'vector_spacing'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("vector_spacing");
    tt->descr = tdrpStrDup("Vector spacing for forecast (km).");
    tt->help = tdrpStrDup("This is the ideal vector spacing - the actual will depend on the motion file grid. Vectors are extracted from the grid at this spacing in x and y.");
    tt->val_offset = (char *) &vector_spacing - &_start_;
    tt->single_val.d = 5;
    tt++;
    
    // Parameter 'smoothing_radius'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("smoothing_radius");
    tt->descr = tdrpStrDup("Smoothing radius (km).");
    tt->help = tdrpStrDup("The influence of each sampled vector is felt out to the smoothing radius. The weight placed on the vector value at any given point within the smoothing radius is inversely proportional to the distance of the point from the vector.");
    tt->val_offset = (char *) &smoothing_radius - &_start_;
    tt->single_val.d = 25;
    tt++;
    
    // Parameter 'u_field_num'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("u_field_num");
    tt->descr = tdrpStrDup("Number of U field (0-based).");
    tt->help = tdrpStrDup("The field number for the U velocity component.");
    tt->val_offset = (char *) &u_field_num - &_start_;
    tt->single_val.l = 0;
    tt++;
    
    // Parameter 'u_plane_ht'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("u_plane_ht");
    tt->descr = tdrpStrDup("Ht of U plane (km).");
    tt->help = tdrpStrDup("The plane height for the U velocity component. The plane closest to this height will be used");
    tt->val_offset = (char *) &u_plane_ht - &_start_;
    tt->single_val.d = 1;
    tt++;
    
    // Parameter 'v_field_num'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("v_field_num");
    tt->descr = tdrpStrDup("Number of V field (0-based).");
    tt->help = tdrpStrDup("The field number for the V velocity component.");
    tt->val_offset = (char *) &v_field_num - &_start_;
    tt->single_val.l = 1;
    tt++;
    
    // Parameter 'v_plane_ht'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("v_plane_ht");
    tt->descr = tdrpStrDup("Ht of V plane (km).");
    tt->help = tdrpStrDup("The plane height for the V velocity component. The plane closest to this height will be used");
    tt->val_offset = (char *) &v_plane_ht - &_start_;
    tt->single_val.d = 1;
    tt++;
    
    // Parameter 'vector_time_margin'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("vector_time_margin");
    tt->descr = tdrpStrDup("Time margin (secs).");
    tt->help = tdrpStrDup("Margin around image grid file time for finding motion grid.");
    tt->val_offset = (char *) &vector_time_margin - &_start_;
    tt->single_val.l = 180;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("");
    tt->comment_text = tdrpStrDup("Image data");
    tt++;
    
    // Parameter 'image_grid_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("image_grid_url");
    tt->descr = tdrpStrDup("Image grid data directory.");
    tt->help = tdrpStrDup("The program takes an image from this directory and creates a forecast using the U and V velocity components from the motion file. The image file used is that closest in time before the motion grid.");
    tt->val_offset = (char *) &image_grid_url - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://localhost::directory");
    tt++;
    
    // Parameter 'image_field_num'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("image_field_num");
    tt->descr = tdrpStrDup("Image field number");
    tt->help = tdrpStrDup("Field number of image data in grid (0-based)");
    tt->val_offset = (char *) &image_field_num - &_start_;
    tt->single_val.l = 0;
    tt++;
    
    // Parameter 'use_image_field_name'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("use_image_field_name");
    tt->descr = tdrpStrDup("Option to use field name instead of field number.\n");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &use_image_field_name - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'image_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("image_field_name");
    tt->descr = tdrpStrDup("Image field name.");
    tt->help = tdrpStrDup("Field name of image data in grid");
    tt->val_offset = (char *) &image_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("dbz");
    tt++;
    
    // Parameter 'image_plane_ht'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("image_plane_ht");
    tt->descr = tdrpStrDup("Image plane height (km MSL).");
    tt->help = tdrpStrDup("Plane height to the image data in grid. The plane closest to this height will be used. Use -1 to use composite (column-max) data.");
    tt->val_offset = (char *) &image_plane_ht - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'image_val_min'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("image_val_min");
    tt->descr = tdrpStrDup("Min value for image data.");
    tt->help = tdrpStrDup("Only include image data above this value in the forecast.");
    tt->val_offset = (char *) &image_val_min - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'image_val_max'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("image_val_max");
    tt->descr = tdrpStrDup("Max value for image data.");
    tt->help = tdrpStrDup("Only include image data below this value in the forecast.");
    tt->val_offset = (char *) &image_val_max - &_start_;
    tt->single_val.d = 255;
    tt++;
    
    // Parameter 'image_time_margin'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("image_time_margin");
    tt->descr = tdrpStrDup("Time margin (secs).");
    tt->help = tdrpStrDup("Margin around motion grid file time for finding image grid.");
    tt->val_offset = (char *) &image_time_margin - &_start_;
    tt->single_val.l = 180;
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("");
    tt->comment_text = tdrpStrDup("Forecast output");
    tt++;
    
    // Parameter 'forecast_output'
    // ctype is '_forecast_output_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("forecast_output");
    tt->descr = tdrpStrDup("Forecast output parameters.");
    tt->help = tdrpStrDup("For each forecast lead time (secs) you must provide an output directory.");
    tt->array_offset = (char *) &_forecast_output - &_start_;
    tt->array_n_offset = (char *) &forecast_output_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(forecast_output_t);
    tt->array_n = 1;
    tt->struct_def.name = tdrpStrDup("forecast_output_t");
    tt->struct_def.nfields = 2;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("url");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_forecast_output->url - (char *) _forecast_output;
      tt->struct_def.fields[1].ftype = tdrpStrDup("long");
      tt->struct_def.fields[1].fname = tdrpStrDup("lead_time");
      tt->struct_def.fields[1].ptype = LONG_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_forecast_output->lead_time - (char *) _forecast_output;
    tt->n_struct_vals = 2;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup("not_set");
      tt->struct_vals[1].l = 0;
    tt++;
    
    // Parameter 'write_to_forecast_directory'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_to_forecast_directory");
    tt->descr = tdrpStrDup("Option to write data to forcast directory structure.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &write_to_forecast_directory - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 6'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 6");
    tt->comment_hdr = tdrpStrDup("");
    tt->comment_text = tdrpStrDup("Optional motion output");
    tt++;
    
    // Parameter 'write_motion_files'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_motion_files");
    tt->descr = tdrpStrDup("Option to output motion grid files for debugging.\n");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &write_motion_files - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'output_motion_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_motion_url");
    tt->descr = tdrpStrDup("Motion grid data URL.");
    tt->help = tdrpStrDup("If 'write_motion_files' is TRUE, motion files will be written to this URL.");
    tt->val_offset = (char *) &output_motion_url - &_start_;
    tt->single_val.s = tdrpStrDup("none");
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
