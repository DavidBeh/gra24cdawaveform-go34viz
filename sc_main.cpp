#include "waveform.hpp"


int sc_main(int argc, char *argv[]) {
    // create new instances of your modules for testing here
    MODULE_B moduleB("b");
    sc_clock clk("clk", 1, SC_SEC);
    moduleB.clk.bind(clk);
    sc_signal<bool> out;
    moduleB.out.bind(out);
    auto tf = sc_create_vcd_trace_file("waveform");
    sc_trace(tf, clk, "clk");
    sc_trace(tf, out, "out");
    sc_trace(tf, moduleB.in1, "A1");
    sc_trace(tf, moduleB.in2, "A2");
    sc_start(14, SC_SEC);
    sc_close_vcd_trace_file(tf);

    std::cout << "out: " << out.read() << std::endl;

    return 0;
}
