// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsync_fifo__Syms.h"


void Vsync_fifo___024root__trace_chg_sub_0(Vsync_fifo___024root* vlSelf, VerilatedVcd* tracep);

void Vsync_fifo___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root__trace_chg_top_0\n"); );
    // Init
    Vsync_fifo___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsync_fifo___024root*>(voidSelf);
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vsync_fifo___024root__trace_chg_sub_0((&vlSymsp->TOP), tracep);
}

void Vsync_fifo___024root__trace_chg_sub_0(Vsync_fifo___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root__trace_chg_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        tracep->chgIData(oldp+0,(vlSelf->sync_fifo__DOT__mem[0]),32);
        tracep->chgIData(oldp+1,(vlSelf->sync_fifo__DOT__mem[1]),32);
        tracep->chgIData(oldp+2,(vlSelf->sync_fifo__DOT__mem[2]),32);
        tracep->chgIData(oldp+3,(vlSelf->sync_fifo__DOT__mem[3]),32);
        tracep->chgIData(oldp+4,(vlSelf->sync_fifo__DOT__mem[4]),32);
        tracep->chgIData(oldp+5,(vlSelf->sync_fifo__DOT__mem[5]),32);
        tracep->chgIData(oldp+6,(vlSelf->sync_fifo__DOT__mem[6]),32);
        tracep->chgIData(oldp+7,(vlSelf->sync_fifo__DOT__mem[7]),32);
        tracep->chgCData(oldp+8,(vlSelf->sync_fifo__DOT__w_ptr),3);
        tracep->chgCData(oldp+9,(vlSelf->sync_fifo__DOT__r_ptr),3);
        tracep->chgCData(oldp+10,(vlSelf->sync_fifo__DOT__count),8);
    }
    tracep->chgBit(oldp+11,(vlSelf->clk));
    tracep->chgBit(oldp+12,(vlSelf->rst));
    tracep->chgBit(oldp+13,(vlSelf->write));
    tracep->chgBit(oldp+14,(vlSelf->read));
    tracep->chgIData(oldp+15,(vlSelf->wData),32);
    tracep->chgIData(oldp+16,(vlSelf->rdData),32);
    tracep->chgBit(oldp+17,(vlSelf->empty));
    tracep->chgBit(oldp+18,(vlSelf->full));
}

void Vsync_fifo___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root__trace_cleanup\n"); );
    // Init
    Vsync_fifo___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsync_fifo___024root*>(voidSelf);
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
