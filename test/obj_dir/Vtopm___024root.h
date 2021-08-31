// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtopm.h for the primary calling header

#ifndef VERILATED_VTOPM___024ROOT_H_
#define VERILATED_VTOPM___024ROOT_H_  // guard

#include "verilated.h"

class Vtopm__Syms;
VL_MODULE(Vtopm___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    Vtopm__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    Vtopm___024root(const char* name);
    ~Vtopm___024root();
    VL_UNCOPYABLE(Vtopm___024root);

    // INTERNAL METHODS
    void __Vconfigure(Vtopm__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
