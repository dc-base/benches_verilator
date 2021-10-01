// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsync_fifo__Syms.h"


VL_ATTR_COLD void Vsync_fifo___024root__trace_init_sub_0(Vsync_fifo___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsync_fifo___024root__trace_init_top(Vsync_fifo___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root__trace_init_top\n"); );
    // Body
    Vsync_fifo___024root__trace_init_sub_0(vlSelf, tracep);
}

VL_ATTR_COLD void Vsync_fifo___024root__trace_init_sub_0(Vsync_fifo___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root__trace_init_sub_0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    tracep->declBit(c+12,"clk", false,-1);
    tracep->declBit(c+13,"rst", false,-1);
    tracep->declBit(c+14,"write", false,-1);
    tracep->declBit(c+15,"read", false,-1);
    tracep->declBus(c+16,"wData", false,-1, 31,0);
    tracep->declBus(c+17,"rdData", false,-1, 31,0);
    tracep->declBit(c+18,"empty", false,-1);
    tracep->declBit(c+19,"full", false,-1);
    tracep->declBit(c+12,"sync_fifo clk", false,-1);
    tracep->declBit(c+13,"sync_fifo rst", false,-1);
    tracep->declBit(c+14,"sync_fifo write", false,-1);
    tracep->declBit(c+15,"sync_fifo read", false,-1);
    tracep->declBus(c+16,"sync_fifo wData", false,-1, 31,0);
    tracep->declBus(c+17,"sync_fifo rdData", false,-1, 31,0);
    tracep->declBit(c+18,"sync_fifo empty", false,-1);
    tracep->declBit(c+19,"sync_fifo full", false,-1);
    {int i; for (i=0; i<8; i++) {
            tracep->declBus(c+1+i*1,"sync_fifo mem", true,(i+0), 31,0);}}
    tracep->declBus(c+9,"sync_fifo w_ptr", false,-1, 2,0);
    tracep->declBus(c+10,"sync_fifo r_ptr", false,-1, 2,0);
    tracep->declBus(c+11,"sync_fifo count", false,-1, 7,0);
    tracep->declBit(c+12,"sync_fifo test clk", false,-1);
    tracep->declBit(c+13,"sync_fifo test rst", false,-1);
    tracep->declBit(c+14,"sync_fifo test write", false,-1);
    tracep->declBit(c+15,"sync_fifo test read", false,-1);
    tracep->declBus(c+16,"sync_fifo test wData", false,-1, 31,0);
    tracep->declBus(c+17,"sync_fifo test rdData", false,-1, 31,0);
    tracep->declBit(c+18,"sync_fifo test empty", false,-1);
    tracep->declBit(c+19,"sync_fifo test full", false,-1);
}

VL_ATTR_COLD void Vsync_fifo___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep);
void Vsync_fifo___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep);
void Vsync_fifo___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vsync_fifo___024root__trace_register(Vsync_fifo___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vsync_fifo___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vsync_fifo___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vsync_fifo___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vsync_fifo___024root__trace_full_sub_0(Vsync_fifo___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsync_fifo___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root__trace_full_top_0\n"); );
    // Init
    Vsync_fifo___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsync_fifo___024root*>(voidSelf);
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsync_fifo___024root__trace_full_sub_0((&vlSymsp->TOP), tracep);
}

VL_ATTR_COLD void Vsync_fifo___024root__trace_full_sub_0(Vsync_fifo___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root__trace_full_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode);
    // Body
    tracep->fullIData(oldp+1,(vlSelf->sync_fifo__DOT__mem[0]),32);
    tracep->fullIData(oldp+2,(vlSelf->sync_fifo__DOT__mem[1]),32);
    tracep->fullIData(oldp+3,(vlSelf->sync_fifo__DOT__mem[2]),32);
    tracep->fullIData(oldp+4,(vlSelf->sync_fifo__DOT__mem[3]),32);
    tracep->fullIData(oldp+5,(vlSelf->sync_fifo__DOT__mem[4]),32);
    tracep->fullIData(oldp+6,(vlSelf->sync_fifo__DOT__mem[5]),32);
    tracep->fullIData(oldp+7,(vlSelf->sync_fifo__DOT__mem[6]),32);
    tracep->fullIData(oldp+8,(vlSelf->sync_fifo__DOT__mem[7]),32);
    tracep->fullCData(oldp+9,(vlSelf->sync_fifo__DOT__w_ptr),3);
    tracep->fullCData(oldp+10,(vlSelf->sync_fifo__DOT__r_ptr),3);
    tracep->fullCData(oldp+11,(vlSelf->sync_fifo__DOT__count),8);
    tracep->fullBit(oldp+12,(vlSelf->clk));
    tracep->fullBit(oldp+13,(vlSelf->rst));
    tracep->fullBit(oldp+14,(vlSelf->write));
    tracep->fullBit(oldp+15,(vlSelf->read));
    tracep->fullIData(oldp+16,(vlSelf->wData),32);
    tracep->fullIData(oldp+17,(vlSelf->rdData),32);
    tracep->fullBit(oldp+18,(vlSelf->empty));
    tracep->fullBit(oldp+19,(vlSelf->full));
}
