// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtopm.h for the primary calling header

#include "verilated.h"

#include "Vtopm___024root.h"

VL_INLINE_OPT void Vtopm___024root___sequent__TOP__2(Vtopm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtopm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtopm___024root___sequent__TOP__2\n"); );
    // Body
    VL_WRITEF("Test of Top Module\n");
}

void Vtopm___024root___eval(Vtopm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtopm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtopm___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtopm___024root___sequent__TOP__2(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vtopm___024root___eval_debug_assertions(Vtopm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtopm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtopm___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
