#ifndef H_WAVEFORM_HPP
#define H_WAVEFORM_HPP

#include <systemc>
using namespace sc_core;

// TODO: Implement the modules MODULE_A and MODULE_B so that their `out` values follow
//       the waveforms described in the exercise description. MODULE_B uses two instances
//       of MODULE_A to compute its output - figure out how.
//       You may add additional signals and/or variables if necessary.

SC_MODULE(MODULE_A) {
  sc_out<bool> out;
  // TODO: Implement module A.
};

SC_MODULE(MODULE_B) {
  MODULE_A a1;
  MODULE_A a2;

  sc_out<bool> out;

  // TODO: Implement module B.
};

#endif