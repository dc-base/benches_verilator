// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop__Syms.h"
#include "Vtop_fifo_if.h"

void Vtop_fifo_if___ctor_var_reset(Vtop_fifo_if* vlSelf);

Vtop_fifo_if::Vtop_fifo_if(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vtop_fifo_if___ctor_var_reset(this);
}

void Vtop_fifo_if::__Vconfigure(Vtop__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vtop_fifo_if::~Vtop_fifo_if() {
}
