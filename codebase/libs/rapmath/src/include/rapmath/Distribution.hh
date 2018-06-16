// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
// ** Copyright UCAR (c) 1990 - 2016                                         
// ** University Corporation for Atmospheric Research (UCAR)                 
// ** National Center for Atmospheric Research (NCAR)                        
// ** Boulder, Colorado, USA                                                 
// ** BSD licence applies - redistribution and use in source and binary      
// ** forms, with or without modification, are permitted provided that       
// ** the following conditions are met:                                      
// ** 1) If the software is modified to produce derivative works,            
// ** such modified software should be clearly marked, so as not             
// ** to confuse it with the version available from UCAR.                    
// ** 2) Redistributions of source code must retain the above copyright      
// ** notice, this list of conditions and the following disclaimer.          
// ** 3) Redistributions in binary form must reproduce the above copyright   
// ** notice, this list of conditions and the following disclaimer in the    
// ** documentation and/or other materials provided with the distribution.   
// ** 4) Neither the name of UCAR nor the names of its contributors,         
// ** if any, may be used to endorse or promote products derived from        
// ** this software without specific prior written permission.               
// ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  
// ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      
// ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
/////////////////////////////////////////////////////////////
// Distribution.hh
//
// Statistical distributions
//
// Mike Dixon, EOL, NCAR, P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// June 2018
//
///////////////////////////////////////////////////////////////

#ifndef Distribution_hh
#define Distribution_hh

#include <string>
#include <vector>
#include <rapmath/stats.h>
#include <cmath>
#include <cstdio>
using namespace std;

////////////////////////
// Base class
//
// Missing or unset values are set to NAN

class Distribution {
  
public:
  
  // constructor
  
  Distribution();
  
  // destructor
  
  virtual ~Distribution();
  
  // debugging
  
  void setDebug(bool state) { _debug = state; }
  void setVerbose(bool state) {
    _verbose = state;
    if (state) setDebug(true);
  }

  // add a data value
  
  void addValue(double xx);

  // set the data values
  
  void setValues(const vector<double> &vals);

  // clear the data value

  void clearValues();

  // compute and return the mean

  double computeMean();

  // compute and return the standard deviation
  // side effects: also computes the mean and variance

  double computeSdev();

  // compute and return the skewness
  // side effects: also computes the mean, sdev and variance

  double computeSkewness();

  // compute and return the kurtosis
  // side effects: also computes the mean, sdev and variance

  double computeKurtosis();

  // compute the basic stats:
  // mean, sdev, variance, skewness and kurtosis

  void computeBasicStats();
  
  // compute histogram
  // if n is not specified, the default is used
  // if histMin is not specified, the min in the data is used
  // if histDelta is not specified, it is computed from data range
  // histMin is the value in the middle of of the first histogram bin
  // histDelta is the delta between the center of adjacent bins
  
  void computeHistogram(size_t n = 60,
                        double histMin = NAN,
                        double histDelta = NAN);
  
  // compute histogram specifying the width of the data in
  // number of standard deviations
  // 
  // nBins is the number of bins
  // the range of x is limited to nsdev (the number of standard
  // deviations) on each side of the mean.
  
  void computeHistogramSpecifyWidth(size_t nBins,
                                    double nSdev);
  
  // perform a fit - abstract base class
  // must be overridden in derived class
  // values must have been set
  // returns 0 on success, -1 on failure
  
  virtual int performFit() = 0;

  // compute the histogram-based CDF
  // assumes the histogram and fit have been computed
  
  void computeHistCdf();

  // get the pdf for a given x
  // must be overridden in derived class

  virtual double getPdf(double xx) = 0;

  // get the cdf for a given x
  // must be overridden in derived class

  virtual double getCdf(double xx) = 0;

  // compute goodness of fit test
  // kk is number of intervals used in test
  
  void computeGof(size_t kk);

  // get methods

  double getMin() const { return _min; }
  double getMax() const { return _max; }
  double getMean() const { return _mean; }
  double getSdev() const { return _sdev; }
  double getVariance() const { return _variance; }
  double getSkewness() const { return _skewness; }
  double getKurtosis() const { return _kurtosis; }
  const vector<double> &getValues() const { return _values; }

  size_t getHistSize() const { return _histSize; }
  double getHistMin() const { return _histMin; }
  double getHistMax() const { return _histMax; }
  double getHistDelta() const { return _histDelta; }

  const vector<double> &getHistX() const { return _histX; }
  const vector<double> &getHistCount() const { return _histCount; }
  const vector<double> &getHistDensity() const { return _histDensity; }
  const vector<double> &getHistPdf() const { return _histPdf; }
  const vector<double> &getHistCdf() const { return _histCdf; }

  double getGof() const { return _gof; }

  // print histogram as text
  
  void printHistogram(FILE *out);

  static const double sqrt2;
  static const double sqrt2Pi;

protected:
  
  bool _debug;
  bool _verbose;

  vector<double> _values;
  size_t _nVals;
  
  double _min;
  double _max;
  double _mean;
  double _median;
  double _mode;
  double _sdev;
  double _variance;
  double _skewness;
  double _kurtosis;

  double _histMin;
  double _histMax;
  double _histDelta;
  size_t _histSize;
  vector<double> _histX;
  vector<double> _histCount;
  vector<double> _histDensity;
  vector<double> _histPdf;
  vector<double> _histCdf;

  bool _pdfAvail;

  double _gof;

  virtual void _clearStats();
  virtual void _clearHist();

private:
  
};

#endif