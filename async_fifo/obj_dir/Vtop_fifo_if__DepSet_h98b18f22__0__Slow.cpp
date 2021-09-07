// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop_fifo_if.h"

VL_ATTR_COLD void Vtop_fifo_if___ctor_var_reset(Vtop_fifo_if* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_fifo_if___ctor_var_reset\n"); );
    // Body
    vlSelf->w_clk = VL_RAND_RESET_I(1);
    vlSelf->r_clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
}
