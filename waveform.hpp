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
    sc_in<bool> clk;
    bool value;
    int counter;
    int stretch;
    // Nicht implemntiert da über MODULE_A geht
    SC_CTOR(MODULE_A);

    MODULE_A(sc_module_name, int stretch) : value(false), stretch(stretch) {
        SC_CTHREAD(behavior, clk);
    }

    void behavior() {
        while (true) {
            wait();
            if (counter++ % stretch == 0) {
                value != value;
                out.write(value);
            }
        }
    }
    // TODO: Implement module A.
};

SC_MODULE(MODULE_B) {
    MODULE_A a1;
    MODULE_A a2;
    sc_in<bool> clk;
    sc_out<bool> out;
    sc_signal<bool> in1, in2;

    SC_CTOR(MODULE_B) : a1("a1", 2), a2("a2", 4){
        a1.out.bind(in1);
        a2.out.bind(in2);
        a1.clk.bind(clk);
        a2.clk.bind(clk);

        SC_THREAD(behavior)
        sensitive << clk.pos();
    }

    void behavior() {
        while(true) {
            wait();
            wait(SC_ZERO_TIME);
            out.write(in1.read() && in2.read());
        }
    }


    // TODO: Implement module B.
};

#endif