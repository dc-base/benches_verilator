// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsync_fifo.h for the primary calling header

#include "verilated.h"

#include "Vsync_fifo__Syms.h"
#include "Vsync_fifo___024root.h"

void Vsync_fifo___024root___ctor_var_reset(Vsync_fifo___024root* vlSelf);

Vsync_fifo___024root::Vsync_fifo___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vsync_fifo___024root___ctor_var_reset(this);
}

void Vsync_fifo___024root::__Vconfigure(Vsync_fifo__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vsync_fifo___024root::~Vsync_fifo___024root() {
}
