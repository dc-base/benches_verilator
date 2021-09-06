// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;
VL_MODULE(Vtop___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(w_clk,0,0);
    VL_IN8(r_clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(we,0,0);
    VL_IN8(re,0,0);
    VL_IN8(din,7,0);
    VL_OUT8(dout,7,0);
    VL_OUT8(full,0,0);
    VL_OUT8(empty,0,0);
    CData/*2:0*/ top__DOT__fifo__DOT__w_ptr;
    CData/*2:0*/ top__DOT__fifo__DOT__r_ptr;
    CData/*7:0*/ top__DOT__fifo__DOT____Vlvbound_h6d3e862e__0;
    CData/*0:0*/ __Vclklast__TOP__r_clk;
    CData/*0:0*/ __Vclklast__TOP__rst;
    CData/*0:0*/ __Vclklast__TOP__w_clk;
    VlUnpacked<CData/*7:0*/, 5> top__DOT__fifo__DOT__mem;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    Vtop___024root(const char* name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(Vtop__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
