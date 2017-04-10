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
// Code for program BrightBand
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
    tt->comment_hdr = tdrpStrDup("BrightBand filters bright-band refelectivies from radar data in a Cartesian grid MDV file.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("PROCESS CONTROL");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'debug'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("debug");
    tt->descr = tdrpStrDup("Debug option");
    tt->help = tdrpStrDup("If set, debug messages will be printed appropriately.");
    tt->val_offset = (char *) &debug - &_start_;
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
    tt->single_val.s = tdrpStrDup("Test");
    tt++;
    
    // Parameter 'mode'
    // ctype is '_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("mode");
    tt->descr = tdrpStrDup("Operation mode");
    tt->help = tdrpStrDup("Program may be run in two modes, archive and realtime. In realtime mode, the analysis is performed for each volume scan as it becomes available. In archive mode, the file list is obtained from the command line.");
    tt->val_offset = (char *) &mode - &_start_;
    tt->enum_def.name = tdrpStrDup("mode_t");
    tt->enum_def.nfields = 2;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("ARCHIVE");
      tt->enum_def.fields[0].val = ARCHIVE;
      tt->enum_def.fields[1].name = tdrpStrDup("REALTIME");
      tt->enum_def.fields[1].val = REALTIME;
    tt->single_val.e = ARCHIVE;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("DATA INPUT");
    tt->comment_text = tdrpStrDup("");
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
    
    // Parameter 'input_data_dir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("input_data_dir");
    tt->descr = tdrpStrDup("URL for input mdv files");
    tt->help = tdrpStrDup("The program will trigger off files in this directory when in realtime mode.");
    tt->val_offset = (char *) &input_data_dir - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://localhost::mdv/radar");
    tt++;
    
    // Parameter 'dbz_label'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("dbz_label");
    tt->descr = tdrpStrDup("Reflectivity field label");
    tt->help = tdrpStrDup("Name found in input mdv files for reflectivity field");
    tt->val_offset = (char *) &dbz_label - &_start_;
    tt->single_val.s = tdrpStrDup("DBZ");
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("ALGORITHM CONTROL");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'max_down'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("max_down");
    tt->descr = tdrpStrDup("Brightband will not be found below this height");
    tt->help = tdrpStrDup("Given in km");
    tt->val_offset = (char *) &max_down - &_start_;
    tt->single_val.d = 2;
    tt++;
    
    // Parameter 'max_up'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("max_up");
    tt->descr = tdrpStrDup("Brightband will not be found above this height");
    tt->help = tdrpStrDup("Given in km");
    tt->val_offset = (char *) &max_up - &_start_;
    tt->single_val.d = 7;
    tt++;
    
    // Parameter 'input_template1'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("input_template1");
    tt->descr = tdrpStrDup("The following values describe a template to be used to detect bright band.");
    tt->help = tdrpStrDup("Specify reflectivity values for each grid point in dBZ");
    tt->array_offset = (char *) &_input_template1 - &_start_;
    tt->array_n_offset = (char *) &input_template1_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(double);
    tt->array_n = 6;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].d = 30;
      tt->array_vals[1].d = 30;
      tt->array_vals[2].d = 45;
      tt->array_vals[3].d = 45;
      tt->array_vals[4].d = 25;
      tt->array_vals[5].d = 25;
    tt++;
    
    // Parameter 'input_template1_info'
    // ctype is '_input_template_info_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("input_template1_info");
    tt->descr = tdrpStrDup("The following contains information pertaining to input_template1");
    tt->help = tdrpStrDup("Note that band_base_idex and band_top_idex describe which number in the template above are the band base and band top respectively.  The first number in the template has an index of 1");
    tt->val_offset = (char *) &input_template1_info - &_start_;
    tt->struct_def.name = tdrpStrDup("input_template_info_t");
    tt->struct_def.nfields = 5;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("boolean");
      tt->struct_def.fields[0].fname = tdrpStrDup("compute_interest");
      tt->struct_def.fields[0].ptype = BOOL_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &input_template1_info.compute_interest - (char *) &input_template1_info;
      tt->struct_def.fields[1].ftype = tdrpStrDup("long");
      tt->struct_def.fields[1].fname = tdrpStrDup("band_base_idex");
      tt->struct_def.fields[1].ptype = LONG_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &input_template1_info.band_base_idex - (char *) &input_template1_info;
      tt->struct_def.fields[2].ftype = tdrpStrDup("long");
      tt->struct_def.fields[2].fname = tdrpStrDup("band_top_idex");
      tt->struct_def.fields[2].ptype = LONG_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &input_template1_info.band_top_idex - (char *) &input_template1_info;
      tt->struct_def.fields[3].ftype = tdrpStrDup("double");
      tt->struct_def.fields[3].fname = tdrpStrDup("min_refl_in_band");
      tt->struct_def.fields[3].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &input_template1_info.min_refl_in_band - (char *) &input_template1_info;
      tt->struct_def.fields[4].ftype = tdrpStrDup("double");
      tt->struct_def.fields[4].fname = tdrpStrDup("max_refl_in_band");
      tt->struct_def.fields[4].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[4].rel_offset = 
        (char *) &input_template1_info.max_refl_in_band - (char *) &input_template1_info;
    tt->n_struct_vals = 5;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].b = pTRUE;
      tt->struct_vals[1].l = 3;
      tt->struct_vals[2].l = 4;
      tt->struct_vals[3].d = 20;
      tt->struct_vals[4].d = 45;
    tt++;
    
    // Parameter 'input_template2'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("input_template2");
    tt->descr = tdrpStrDup("The following values describe a template to be used to detect bright band.");
    tt->help = tdrpStrDup("Specify reflectivity values for each grid point in dBZ");
    tt->array_offset = (char *) &_input_template2 - &_start_;
    tt->array_n_offset = (char *) &input_template2_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(double);
    tt->array_n = 5;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].d = 30;
      tt->array_vals[1].d = 30;
      tt->array_vals[2].d = 45;
      tt->array_vals[3].d = 25;
      tt->array_vals[4].d = 25;
    tt++;
    
    // Parameter 'input_template2_info'
    // ctype is '_input_template_info_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("input_template2_info");
    tt->descr = tdrpStrDup("The following contains information pertaining to input_template2");
    tt->help = tdrpStrDup("Note that band_base_idex and band_top_idex describe which number in the template above are the band base and band top respectively.  The first number in the template has an index of 1");
    tt->val_offset = (char *) &input_template2_info - &_start_;
    tt->struct_def.name = tdrpStrDup("input_template_info_t");
    tt->struct_def.nfields = 5;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("boolean");
      tt->struct_def.fields[0].fname = tdrpStrDup("compute_interest");
      tt->struct_def.fields[0].ptype = BOOL_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &input_template2_info.compute_interest - (char *) &input_template2_info;
      tt->struct_def.fields[1].ftype = tdrpStrDup("long");
      tt->struct_def.fields[1].fname = tdrpStrDup("band_base_idex");
      tt->struct_def.fields[1].ptype = LONG_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &input_template2_info.band_base_idex - (char *) &input_template2_info;
      tt->struct_def.fields[2].ftype = tdrpStrDup("long");
      tt->struct_def.fields[2].fname = tdrpStrDup("band_top_idex");
      tt->struct_def.fields[2].ptype = LONG_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &input_template2_info.band_top_idex - (char *) &input_template2_info;
      tt->struct_def.fields[3].ftype = tdrpStrDup("double");
      tt->struct_def.fields[3].fname = tdrpStrDup("min_refl_in_band");
      tt->struct_def.fields[3].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &input_template2_info.min_refl_in_band - (char *) &input_template2_info;
      tt->struct_def.fields[4].ftype = tdrpStrDup("double");
      tt->struct_def.fields[4].fname = tdrpStrDup("max_refl_in_band");
      tt->struct_def.fields[4].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[4].rel_offset = 
        (char *) &input_template2_info.max_refl_in_band - (char *) &input_template2_info;
    tt->n_struct_vals = 5;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].b = pTRUE;
      tt->struct_vals[1].l = 3;
      tt->struct_vals[2].l = 3;
      tt->struct_vals[3].d = 20;
      tt->struct_vals[4].d = 45;
    tt++;
    
    // Parameter 'input_template3'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("input_template3");
    tt->descr = tdrpStrDup("The following values describe a template to be used to detect bright band.");
    tt->help = tdrpStrDup("Specify reflectivity values for each grid point in dBZ");
    tt->array_offset = (char *) &_input_template3 - &_start_;
    tt->array_n_offset = (char *) &input_template3_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(double);
    tt->array_n = 6;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].d = 30;
      tt->array_vals[1].d = 45;
      tt->array_vals[2].d = 45;
      tt->array_vals[3].d = 45;
      tt->array_vals[4].d = 45;
      tt->array_vals[5].d = 25;
    tt++;
    
    // Parameter 'input_template3_info'
    // ctype is '_input_template_info_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("input_template3_info");
    tt->descr = tdrpStrDup("The following contains information pertaining to input_template3");
    tt->help = tdrpStrDup("Note that band_base_idex and band_top_idex describe which number in the template above are the band base and band top respectively.  The first number in the template has an index of 1");
    tt->val_offset = (char *) &input_template3_info - &_start_;
    tt->struct_def.name = tdrpStrDup("input_template_info_t");
    tt->struct_def.nfields = 5;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("boolean");
      tt->struct_def.fields[0].fname = tdrpStrDup("compute_interest");
      tt->struct_def.fields[0].ptype = BOOL_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &input_template3_info.compute_interest - (char *) &input_template3_info;
      tt->struct_def.fields[1].ftype = tdrpStrDup("long");
      tt->struct_def.fields[1].fname = tdrpStrDup("band_base_idex");
      tt->struct_def.fields[1].ptype = LONG_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &input_template3_info.band_base_idex - (char *) &input_template3_info;
      tt->struct_def.fields[2].ftype = tdrpStrDup("long");
      tt->struct_def.fields[2].fname = tdrpStrDup("band_top_idex");
      tt->struct_def.fields[2].ptype = LONG_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &input_template3_info.band_top_idex - (char *) &input_template3_info;
      tt->struct_def.fields[3].ftype = tdrpStrDup("double");
      tt->struct_def.fields[3].fname = tdrpStrDup("min_refl_in_band");
      tt->struct_def.fields[3].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &input_template3_info.min_refl_in_band - (char *) &input_template3_info;
      tt->struct_def.fields[4].ftype = tdrpStrDup("double");
      tt->struct_def.fields[4].fname = tdrpStrDup("max_refl_in_band");
      tt->struct_def.fields[4].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[4].rel_offset = 
        (char *) &input_template3_info.max_refl_in_band - (char *) &input_template3_info;
    tt->n_struct_vals = 5;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].b = pFALSE;
      tt->struct_vals[1].l = 2;
      tt->struct_vals[2].l = 5;
      tt->struct_vals[3].d = 20;
      tt->struct_vals[4].d = 45;
    tt++;
    
    // Parameter 'interest_threshold'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("interest_threshold");
    tt->descr = tdrpStrDup("Interest threshold");
    tt->help = tdrpStrDup("Interest values below this threshold will not be used in identifying areas of brightband");
    tt->val_offset = (char *) &interest_threshold - &_start_;
    tt->single_val.d = 0.6;
    tt++;
    
    // Parameter 'area_threshold_sq_km'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("area_threshold_sq_km");
    tt->descr = tdrpStrDup("Area threshold");
    tt->help = tdrpStrDup("The smallest area in square km that should be considered brightband");
    tt->val_offset = (char *) &area_threshold_sq_km - &_start_;
    tt->single_val.l = 50;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("DATA OUTPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'output_dir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_dir");
    tt->descr = tdrpStrDup("URL for output mdv files");
    tt->help = tdrpStrDup("Filtered data written to mdv files in this URL");
    tt->val_offset = (char *) &output_dir - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://localhost::mdv/brightBand");
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("ENCODING AND COMPRESSION CONVERSION");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'output_encoding'
    // ctype is '_encoding_type_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("output_encoding");
    tt->descr = tdrpStrDup("Set encoding type for output files.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &output_encoding - &_start_;
    tt->enum_def.name = tdrpStrDup("encoding_type_t");
    tt->enum_def.nfields = 4;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("ENCODING_ASIS");
      tt->enum_def.fields[0].val = ENCODING_ASIS;
      tt->enum_def.fields[1].name = tdrpStrDup("ENCODING_INT8");
      tt->enum_def.fields[1].val = ENCODING_INT8;
      tt->enum_def.fields[2].name = tdrpStrDup("ENCODING_INT16");
      tt->enum_def.fields[2].val = ENCODING_INT16;
      tt->enum_def.fields[3].name = tdrpStrDup("ENCODING_FLOAT32");
      tt->enum_def.fields[3].val = ENCODING_FLOAT32;
    tt->single_val.e = ENCODING_ASIS;
    tt++;
    
    // Parameter 'output_compression'
    // ctype is '_compression_type_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("output_compression");
    tt->descr = tdrpStrDup("Set compression type for output files.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &output_compression - &_start_;
    tt->enum_def.name = tdrpStrDup("compression_type_t");
    tt->enum_def.nfields = 4;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("COMPRESSION_ASIS");
      tt->enum_def.fields[0].val = COMPRESSION_ASIS;
      tt->enum_def.fields[1].name = tdrpStrDup("COMPRESSION_NONE");
      tt->enum_def.fields[1].val = COMPRESSION_NONE;
      tt->enum_def.fields[2].name = tdrpStrDup("COMPRESSION_BZIP2");
      tt->enum_def.fields[2].val = COMPRESSION_BZIP2;
      tt->enum_def.fields[3].name = tdrpStrDup("COMPRESSION_GZIP");
      tt->enum_def.fields[3].val = COMPRESSION_GZIP;
    tt->single_val.e = COMPRESSION_GZIP;
    tt++;
    
    // Parameter 'Comment 6'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 6");
    tt->comment_hdr = tdrpStrDup("WRITING INTERMEDIATE FIELDS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'write_interest'
    // ctype is '_write_interest_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("write_interest");
    tt->descr = tdrpStrDup("Describes when to write interest fields to an mdv file");
    tt->help = tdrpStrDup("Options are to always write the interest fields to an mdv file, to only write interest fields to an mdv file when areas of brightband are identified and filtered, or to never write the interest fields to an mdv file");
    tt->val_offset = (char *) &write_interest - &_start_;
    tt->enum_def.name = tdrpStrDup("write_interest_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("ALWAYS");
      tt->enum_def.fields[0].val = ALWAYS;
      tt->enum_def.fields[1].name = tdrpStrDup("BRIGHTBAND_FOUND");
      tt->enum_def.fields[1].val = BRIGHTBAND_FOUND;
      tt->enum_def.fields[2].name = tdrpStrDup("NEVER");
      tt->enum_def.fields[2].val = NEVER;
    tt->single_val.e = NEVER;
    tt++;
    
    // Parameter 'interest_dir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("interest_dir");
    tt->descr = tdrpStrDup("URL for interest mdv files");
    tt->help = tdrpStrDup("Interest values written to mdv files in this URL");
    tt->val_offset = (char *) &interest_dir - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://localhost::mdv/interest");
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
