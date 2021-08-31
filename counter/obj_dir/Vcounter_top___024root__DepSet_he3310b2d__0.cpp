// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcounter_top.h for the primary calling header

#include "verilated.h"

#include "Vcounter_top___024root.h"

VL_INLINE_OPT void Vcounter_top___024root___sequent__TOP__1(Vcounter_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_top___024root___sequent__TOP__1\n"); );
    // Body
    VL_WRITEF("%3#\n",8,vlSelf->count);
    vlSelf->count = ((0x7fU == VL_EXTENDS_II(32,8, (IData)(vlSelf->count)))
                      ? 0U : (0xffU & ((IData)(1U) 
                                       + VL_EXTENDS_II(8,8, (IData)(vlSelf->count)))));
}

void Vcounter_top___024root___eval(Vcounter_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_top___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vcounter_top___024root___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vcounter_top___024root___eval_debug_assertions(Vcounter_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
