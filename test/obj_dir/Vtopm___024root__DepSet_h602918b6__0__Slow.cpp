// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtopm.h for the primary calling header

#include "verilated.h"

#include "Vtopm___024root.h"

VL_ATTR_COLD void Vtopm___024root___initial__TOP__1(Vtopm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtopm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtopm___024root___initial__TOP__1\n"); );
    // Body
    VL_WRITEF("Top initial begin\n");
}

VL_ATTR_COLD void Vtopm___024root___eval_initial(Vtopm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtopm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtopm___024root___eval_initial\n"); );
    // Body
    Vtopm___024root___initial__TOP__1(vlSelf);
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vtopm___024root___eval_settle(Vtopm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtopm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtopm___024root___eval_settle\n"); );
}

VL_ATTR_COLD void Vtopm___024root___final(Vtopm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtopm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtopm___024root___final\n"); );
}

VL_ATTR_COLD void Vtopm___024root___ctor_var_reset(Vtopm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtopm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtopm___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
}
