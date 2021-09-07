// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_FIFO_IF_H_
#define VERILATED_VTOP_FIFO_IF_H_  // guard

#include "verilated.h"

class Vtop__Syms;
VL_MODULE(Vtop_fifo_if) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(w_clk,0,0);
    VL_IN8(r_clk,0,0);
    VL_IN8(rst,0,0);

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    Vtop_fifo_if(const char* name);
    ~Vtop_fifo_if();
    VL_UNCOPYABLE(Vtop_fifo_if);

    // INTERNAL METHODS
    void __Vconfigure(Vtop__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
