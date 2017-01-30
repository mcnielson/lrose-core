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
// Code for program Binary2Mdv
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

    // Parameter 'debug_level'
    // ctype is '_debug_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("debug_level");
    tt->descr = tdrpStrDup("Debug option");
    tt->help = tdrpStrDup("If set, debug messages will be printed appropriately");
    tt->val_offset = (char *) &debug_level - &_start_;
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
      tt->enum_def.fields[3].name = tdrpStrDup("DEBUG_EXTRA");
      tt->enum_def.fields[3].val = DEBUG_EXTRA;
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
    
    // Parameter 'run_mode'
    // ctype is '_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("run_mode");
    tt->descr = tdrpStrDup("Operational mode");
    tt->help = tdrpStrDup("Realtime mode - waits for new data; archive mode runs on file list");
    tt->val_offset = (char *) &run_mode - &_start_;
    tt->enum_def.name = tdrpStrDup("mode_t");
    tt->enum_def.nfields = 2;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("REALTIME");
      tt->enum_def.fields[0].val = REALTIME;
      tt->enum_def.fields[1].name = tdrpStrDup("ARCHIVE");
      tt->enum_def.fields[1].val = ARCHIVE;
    tt->single_val.e = REALTIME;
    tt++;
    
    // Parameter 'input_file_substring'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("input_file_substring");
    tt->descr = tdrpStrDup("Input file substring");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &input_file_substring - &_start_;
    tt->single_val.s = tdrpStrDup("p37cr");
    tt++;
    
    // Parameter 'input_dir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("input_dir");
    tt->descr = tdrpStrDup("Input directory");
    tt->help = tdrpStrDup("Path of input directory - realtime mode only");
    tt->val_offset = (char *) &input_dir - &_start_;
    tt->single_val.s = tdrpStrDup(".");
    tt++;
    
    // Parameter 'output_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_url");
    tt->descr = tdrpStrDup("Output url");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &output_url - &_start_;
    tt->single_val.s = tdrpStrDup(".");
    tt++;
    
    // Parameter 'start_time_offset'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("start_time_offset");
    tt->descr = tdrpStrDup("file start time offset");
    tt->help = tdrpStrDup("The number of seconds to be subtracted from the Unisys data time to get the MDV file start time.  Use a negative value if the start time should be later than the data time.");
    tt->val_offset = (char *) &start_time_offset - &_start_;
    tt->single_val.l = 300;
    tt++;
    
    // Parameter 'mid_time_offset'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("mid_time_offset");
    tt->descr = tdrpStrDup("file centroid time offset");
    tt->help = tdrpStrDup("The number of seconds to be added to the Unisys data time to get the MDV file centroid time.  Use a negative number if the file centroid time should precede the Unisys data time.");
    tt->val_offset = (char *) &mid_time_offset - &_start_;
    tt->single_val.l = 0;
    tt++;
    
    // Parameter 'end_time_offset'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("end_time_offset");
    tt->descr = tdrpStrDup("file end time offset");
    tt->help = tdrpStrDup("The number of seconds to be added to the Unisys data time to get the MDV file end time.  Use a negative number if the file end time should precede the Unisys data time.");
    tt->val_offset = (char *) &end_time_offset - &_start_;
    tt->single_val.l = 150;
    tt++;
    
    // Parameter 'max_input_data_age'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("max_input_data_age");
    tt->descr = tdrpStrDup("Max age of input data");
    tt->help = tdrpStrDup("For realtime only - max age of input data for it to be valid");
    tt->val_offset = (char *) &max_input_data_age - &_start_;
    tt->has_min = TRUE;
    tt->min_val.l = 60;
    tt->single_val.l = 300;
    tt++;
    
    // Parameter 'processing_delay'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("processing_delay");
    tt->descr = tdrpStrDup("Delay before processing incoming file (sec)");
    tt->help = tdrpStrDup("Delay between finding new file and processing it - realtime only (sec)");
    tt->val_offset = (char *) &processing_delay - &_start_;
    tt->has_min = TRUE;
    tt->has_max = TRUE;
    tt->min_val.l = 0;
    tt->max_val.l = 300;
    tt->single_val.l = 10;
    tt++;
    
    // Parameter 'data_field_name_long'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("data_field_name_long");
    tt->descr = tdrpStrDup("field name for data -- long form");
    tt->help = tdrpStrDup("This value is put in the MDV field header.");
    tt->val_offset = (char *) &data_field_name_long - &_start_;
    tt->single_val.s = tdrpStrDup("Refectivity");
    tt++;
    
    // Parameter 'data_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("data_field_name");
    tt->descr = tdrpStrDup("field name for data -- short form");
    tt->help = tdrpStrDup("This value is put in the MDV field header.");
    tt->val_offset = (char *) &data_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("refl");
    tt++;
    
    // Parameter 'data_units'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("data_units");
    tt->descr = tdrpStrDup("data units");
    tt->help = tdrpStrDup("This value is put in the MDV field header.");
    tt->val_offset = (char *) &data_units - &_start_;
    tt->single_val.s = tdrpStrDup("dBZ");
    tt++;
    
    // Parameter 'bad_data_value'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("bad_data_value");
    tt->descr = tdrpStrDup("Bad data value.");
    tt->help = tdrpStrDup("Data with this value (BEFORE applying scale and bias) not valid.");
    tt->val_offset = (char *) &bad_data_value - &_start_;
    tt->single_val.d = -99;
    tt++;
    
    // Parameter 'missing_data_value'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("missing_data_value");
    tt->descr = tdrpStrDup("Missing data value.");
    tt->help = tdrpStrDup("Data with this value (BEFORE applying scale and bias) not measured.");
    tt->val_offset = (char *) &missing_data_value - &_start_;
    tt->single_val.d = -98;
    tt++;
    
    // Parameter 'is_bigend'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("is_bigend");
    tt->descr = tdrpStrDup("Flag indicating if data is big endian or little endian");
    tt->help = tdrpStrDup("If true, the data is assumed to be big endian");
    tt->val_offset = (char *) &is_bigend - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'input_proj'
    // ctype is '_proj_info_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("input_proj");
    tt->descr = tdrpStrDup("Projection information for data coming in");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &input_proj - &_start_;
    tt->struct_def.name = tdrpStrDup("proj_info_t");
    tt->struct_def.nfields = 13;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("proj_type_t");
      tt->struct_def.fields[0].fname = tdrpStrDup("proj_type");
      tt->struct_def.fields[0].ptype = ENUM_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &input_proj.proj_type - (char *) &input_proj;
        tt->struct_def.fields[0].enum_def.name = tdrpStrDup("proj_type_t");
        tt->struct_def.fields[0].enum_def.nfields = 2;
        tt->struct_def.fields[0].enum_def.fields = (enum_field_t *) tdrpMalloc
          (tt->struct_def.fields[0].enum_def.nfields * sizeof(enum_field_t));
        tt->struct_def.fields[0].enum_def.fields[0].name = tdrpStrDup("PROJ_TYPE_LAT_LON");
        tt->struct_def.fields[0].enum_def.fields[0].val = PROJ_TYPE_LAT_LON;
        tt->struct_def.fields[0].enum_def.fields[1].name = tdrpStrDup("PROJ_TYPE_FLAT");
        tt->struct_def.fields[0].enum_def.fields[1].val = PROJ_TYPE_FLAT;
      tt->struct_def.fields[1].ftype = tdrpStrDup("double");
      tt->struct_def.fields[1].fname = tdrpStrDup("minx");
      tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &input_proj.minx - (char *) &input_proj;
      tt->struct_def.fields[2].ftype = tdrpStrDup("double");
      tt->struct_def.fields[2].fname = tdrpStrDup("miny");
      tt->struct_def.fields[2].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &input_proj.miny - (char *) &input_proj;
      tt->struct_def.fields[3].ftype = tdrpStrDup("double");
      tt->struct_def.fields[3].fname = tdrpStrDup("minz");
      tt->struct_def.fields[3].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &input_proj.minz - (char *) &input_proj;
      tt->struct_def.fields[4].ftype = tdrpStrDup("double");
      tt->struct_def.fields[4].fname = tdrpStrDup("dx");
      tt->struct_def.fields[4].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[4].rel_offset = 
        (char *) &input_proj.dx - (char *) &input_proj;
      tt->struct_def.fields[5].ftype = tdrpStrDup("double");
      tt->struct_def.fields[5].fname = tdrpStrDup("dy");
      tt->struct_def.fields[5].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[5].rel_offset = 
        (char *) &input_proj.dy - (char *) &input_proj;
      tt->struct_def.fields[6].ftype = tdrpStrDup("double");
      tt->struct_def.fields[6].fname = tdrpStrDup("dz");
      tt->struct_def.fields[6].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[6].rel_offset = 
        (char *) &input_proj.dz - (char *) &input_proj;
      tt->struct_def.fields[7].ftype = tdrpStrDup("long");
      tt->struct_def.fields[7].fname = tdrpStrDup("nx");
      tt->struct_def.fields[7].ptype = LONG_TYPE;
      tt->struct_def.fields[7].rel_offset = 
        (char *) &input_proj.nx - (char *) &input_proj;
      tt->struct_def.fields[8].ftype = tdrpStrDup("long");
      tt->struct_def.fields[8].fname = tdrpStrDup("ny");
      tt->struct_def.fields[8].ptype = LONG_TYPE;
      tt->struct_def.fields[8].rel_offset = 
        (char *) &input_proj.ny - (char *) &input_proj;
      tt->struct_def.fields[9].ftype = tdrpStrDup("long");
      tt->struct_def.fields[9].fname = tdrpStrDup("nz");
      tt->struct_def.fields[9].ptype = LONG_TYPE;
      tt->struct_def.fields[9].rel_offset = 
        (char *) &input_proj.nz - (char *) &input_proj;
      tt->struct_def.fields[10].ftype = tdrpStrDup("double");
      tt->struct_def.fields[10].fname = tdrpStrDup("origin_lat");
      tt->struct_def.fields[10].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[10].rel_offset = 
        (char *) &input_proj.origin_lat - (char *) &input_proj;
      tt->struct_def.fields[11].ftype = tdrpStrDup("double");
      tt->struct_def.fields[11].fname = tdrpStrDup("origin_lon");
      tt->struct_def.fields[11].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[11].rel_offset = 
        (char *) &input_proj.origin_lon - (char *) &input_proj;
      tt->struct_def.fields[12].ftype = tdrpStrDup("double");
      tt->struct_def.fields[12].fname = tdrpStrDup("rotation");
      tt->struct_def.fields[12].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[12].rel_offset = 
        (char *) &input_proj.rotation - (char *) &input_proj;
    tt->n_struct_vals = 13;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].e = PROJ_TYPE_LAT_LON;
      tt->struct_vals[1].d = -124.995;
      tt->struct_vals[2].d = 32.005;
      tt->struct_vals[3].d = 0.5;
      tt->struct_vals[4].d = 0.01;
      tt->struct_vals[5].d = 0.01;
      tt->struct_vals[6].d = 0.5;
      tt->struct_vals[7].l = 1501;
      tt->struct_vals[8].l = 1201;
      tt->struct_vals[9].l = 21;
      tt->struct_vals[10].d = 0;
      tt->struct_vals[11].d = 0;
      tt->struct_vals[12].d = 0;
    tt++;
    
    // Parameter 'Vlevels'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("Vlevels");
    tt->descr = tdrpStrDup("Vlevels");
    tt->help = tdrpStrDup("Vertical levels found in data");
    tt->array_offset = (char *) &_Vlevels - &_start_;
    tt->array_n_offset = (char *) &Vlevels_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(double);
    tt->array_n = 6;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].d = 0.5;
      tt->array_vals[1].d = 1;
      tt->array_vals[2].d = 1.5;
      tt->array_vals[3].d = 2;
      tt->array_vals[4].d = 2.5;
      tt->array_vals[5].d = 3;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
