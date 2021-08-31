// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcounter_top.h for the primary calling header

#ifndef VERILATED_VCOUNTER_TOP___024ROOT_H_
#define VERILATED_VCOUNTER_TOP___024ROOT_H_  // guard

#include "verilated.h"

class Vcounter_top__Syms;
VL_MODULE(Vcounter_top___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_OUT8(count,7,0);
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    Vcounter_top__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    Vcounter_top___024root(const char* name);
    ~Vcounter_top___024root();
    VL_UNCOPYABLE(Vcounter_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(Vcounter_top__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
