// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__2\n"); );
    // Body
    if (vlSelf->rst) {
        if (((IData)(vlSelf->re) & (~ (IData)(vlSelf->empty)))) {
            vlSelf->dout = ((4U >= (IData)(vlSelf->top__DOT__fifo__DOT__r_ptr))
                             ? vlSelf->top__DOT__fifo__DOT__mem
                            [vlSelf->top__DOT__fifo__DOT__r_ptr]
                             : 0U);
            vlSelf->top__DOT__fifo__DOT__r_ptr = 0U;
        }
    } else {
        vlSelf->top__DOT__fifo__DOT__r_ptr = 0U;
    }
}

VL_INLINE_OPT void Vtop___024root___sequent__TOP__3(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__3\n"); );
    // Init
    CData/*2:0*/ __Vdlyvdim0__top__DOT__fifo__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__fifo__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__fifo__DOT__mem__v0;
    // Body
    __Vdlyvset__top__DOT__fifo__DOT__mem__v0 = 0U;
    if (vlSelf->rst) {
        if (((IData)(vlSelf->we) & (~ (IData)(vlSelf->full)))) {
            vlSelf->top__DOT__fifo__DOT____Vlvbound_h6d3e862e__0 
                = vlSelf->din;
            if ((4U >= (IData)(vlSelf->top__DOT__fifo__DOT__w_ptr))) {
                __Vdlyvval__top__DOT__fifo__DOT__mem__v0 
                    = vlSelf->top__DOT__fifo__DOT____Vlvbound_h6d3e862e__0;
                __Vdlyvset__top__DOT__fifo__DOT__mem__v0 = 1U;
                __Vdlyvdim0__top__DOT__fifo__DOT__mem__v0 
                    = vlSelf->top__DOT__fifo__DOT__w_ptr;
            }
            vlSelf->top__DOT__fifo__DOT__w_ptr = (7U 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->top__DOT__fifo__DOT__w_ptr)));
        }
    } else {
        vlSelf->top__DOT__fifo__DOT__w_ptr = 0U;
    }
    if (__Vdlyvset__top__DOT__fifo__DOT__mem__v0) {
        vlSelf->top__DOT__fifo__DOT__mem[__Vdlyvdim0__top__DOT__fifo__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__fifo__DOT__mem__v0;
    }
    vlSelf->full = (4U == (IData)(vlSelf->top__DOT__fifo__DOT__w_ptr));
    vlSelf->empty = (0U == (IData)(vlSelf->top__DOT__fifo__DOT__w_ptr));
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->r_clk) & (~ (IData)(vlSelf->__Vclklast__TOP__r_clk))) 
         | ((~ (IData)(vlSelf->rst)) & (IData)(vlSelf->__Vclklast__TOP__rst)))) {
        Vtop___024root___sequent__TOP__2(vlSelf);
    }
    if ((((~ (IData)(vlSelf->rst)) & (IData)(vlSelf->__Vclklast__TOP__rst)) 
         | ((IData)(vlSelf->w_clk) & (~ (IData)(vlSelf->__Vclklast__TOP__w_clk))))) {
        Vtop___024root___sequent__TOP__3(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__r_clk = vlSelf->r_clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
    vlSelf->__Vclklast__TOP__w_clk = vlSelf->w_clk;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->w_clk & 0xfeU))) {
        Verilated::overWidthError("w_clk");}
    if (VL_UNLIKELY((vlSelf->r_clk & 0xfeU))) {
        Verilated::overWidthError("r_clk");}
    if (VL_UNLIKELY((vlSelf->we & 0xfeU))) {
        Verilated::overWidthError("we");}
    if (VL_UNLIKELY((vlSelf->re & 0xfeU))) {
        Verilated::overWidthError("re");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
