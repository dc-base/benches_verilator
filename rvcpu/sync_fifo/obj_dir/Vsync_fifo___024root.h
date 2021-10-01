// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsync_fifo.h for the primary calling header

#ifndef VERILATED_VSYNC_FIFO___024ROOT_H_
#define VERILATED_VSYNC_FIFO___024ROOT_H_  // guard

#include "verilated.h"

class Vsync_fifo__Syms;
VL_MODULE(Vsync_fifo___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(write,0,0);
    VL_IN8(read,0,0);
    VL_OUT8(empty,0,0);
    VL_OUT8(full,0,0);
    CData/*2:0*/ sync_fifo__DOT__w_ptr;
    CData/*2:0*/ sync_fifo__DOT__r_ptr;
    CData/*7:0*/ sync_fifo__DOT__count;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst;
    VL_IN(wData,31,0);
    VL_OUT(rdData,31,0);
    VlUnpacked<IData/*31:0*/, 8> sync_fifo__DOT__mem;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vsync_fifo__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    Vsync_fifo___024root(const char* name);
    ~Vsync_fifo___024root();
    VL_UNCOPYABLE(Vsync_fifo___024root);

    // INTERNAL METHODS
    void __Vconfigure(Vsync_fifo__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
