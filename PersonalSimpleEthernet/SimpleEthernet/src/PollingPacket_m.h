//
// Generated file, do not edit! Created by opp_msgtool 6.0 from PollingPacket.msg.
//

#ifndef __POLLINGPACKET_M_H
#define __POLLINGPACKET_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

class PollingRequest;
class PollingData;
struct FlowTableEntry;
class FlowTableParameters;
/**
 * Class generated from <tt>PollingPacket.msg:1</tt> by opp_msgtool.
 * <pre>
 * packet PollingRequest
 * {
 *     //pollingBurst = numero di messaggi che si possono inviare sul canale con la richiesta polling
 *     int requestedFrames;
 * 
 *     //nome flusso (ogni PollingRequest si riferisce ad un certo flusso applicativo)
 *     string flow;
 * 
 *     //priorita' di schedulazione delle polling request (quindi del traffico dalle varie applicazioni): + basso e' il valore, > e' la priorita'
 *     long priority;
 * 
 *     uint64_t trxno; //numero di transazione per identificare la polling request e il polling data associato (campo a 8 byte)
 * 
 *     //8 (long generalmente a 64 bit) per priority, 8 per trxno, 4 per requestedFrames (int generalmente a 32 bit), 2 per il nome del flusso
 *     byteLength = 22;
 * 
 * }
 * </pre>
 */
class PollingRequest : public ::omnetpp::cPacket
{
  protected:
    int requestedFrames = 0;
    omnetpp::opp_string flow;
    long priority = 0;
    uint64_t trxno = 0;

  private:
    void copy(const PollingRequest& other);

  protected:
    bool operator==(const PollingRequest&) = delete;

  public:
    PollingRequest(const char *name=nullptr, short kind=0);
    PollingRequest(const PollingRequest& other);
    virtual ~PollingRequest();
    PollingRequest& operator=(const PollingRequest& other);
    virtual PollingRequest *dup() const override {return new PollingRequest(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getRequestedFrames() const;
    virtual void setRequestedFrames(int requestedFrames);

    virtual const char * getFlow() const;
    virtual void setFlow(const char * flow);

    virtual long getPriority() const;
    virtual void setPriority(long priority);

    virtual uint64_t getTrxno() const;
    virtual void setTrxno(uint64_t trxno);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const PollingRequest& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, PollingRequest& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>PollingPacket.msg:20</tt> by opp_msgtool.
 * <pre>
 * //messaggio che serve al Polling Controller
 * packet PollingData
 * {
 *     string destination;//destinazione del burst di pacchetti generati dall'applicazione (cioe' la destinazione del pacchetto applicativo incapsulato)
 *     uint64_t trxno; //identificativo della transazione (richiesta di trasmissione con PollingRequest e trasmissione del dato nel PollingData)
 *     byteLength = 15;  //6 byte del MAC address + 8 byte del numero di transazione + 1 byte del campo last
 * 
 *     //flag settato a true solo per l'ultimo frame del burst (occupa 1 byte)
 *     //(ogni pacchetto corrisponde a un frame, quindi abbiamo un burst di pacchetti e un burst di frame) 
 *     bool last = false;
 * }
 * </pre>
 */
class PollingData : public ::omnetpp::cPacket
{
  protected:
    omnetpp::opp_string destination;
    uint64_t trxno = 0;
    bool last = false;

  private:
    void copy(const PollingData& other);

  protected:
    bool operator==(const PollingData&) = delete;

  public:
    PollingData(const char *name=nullptr, short kind=0);
    PollingData(const PollingData& other);
    virtual ~PollingData();
    PollingData& operator=(const PollingData& other);
    virtual PollingData *dup() const override {return new PollingData(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const char * getDestination() const;
    virtual void setDestination(const char * destination);

    virtual uint64_t getTrxno() const;
    virtual void setTrxno(uint64_t trxno);

    virtual bool getLast() const;
    virtual void setLast(bool last);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const PollingData& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, PollingData& obj) {obj.parsimUnpack(b);}

/**
 * Struct generated from PollingPacket.msg:32 by opp_msgtool.
 */
struct FlowTableEntry
{
    FlowTableEntry();
    omnetpp::opp_string addr;
    omnetpp::opp_string flow;
    int burst = 0;
    omnetpp::simtime_t period = SIMTIME_ZERO;
    omnetpp::simtime_t deadline = SIMTIME_ZERO;
};

// helpers for local use
void __doPacking(omnetpp::cCommBuffer *b, const FlowTableEntry& a);
void __doUnpacking(omnetpp::cCommBuffer *b, FlowTableEntry& a);

inline void doParsimPacking(omnetpp::cCommBuffer *b, const FlowTableEntry& obj) { __doPacking(b, obj); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, FlowTableEntry& obj) { __doUnpacking(b, obj); }

/**
 * Class generated from <tt>PollingPacket.msg:41</tt> by opp_msgtool.
 * <pre>
 * //definisco la classe che, incapsulando un array di FlowTableEntry, modella l'intera tabella dei flussi
 * class FlowTableParameters extends cOwnedObject
 * {
 *     FlowTableEntry flows[];
 * }
 * </pre>
 */
class FlowTableParameters : public ::omnetpp::cOwnedObject
{
  protected:
    FlowTableEntry *flows = nullptr;
    size_t flows_arraysize = 0;

  private:
    void copy(const FlowTableParameters& other);

  protected:
    bool operator==(const FlowTableParameters&) = delete;

  public:
    FlowTableParameters(const char *name=nullptr);
    FlowTableParameters(const FlowTableParameters& other);
    virtual ~FlowTableParameters();
    FlowTableParameters& operator=(const FlowTableParameters& other);
    virtual FlowTableParameters *dup() const override {return new FlowTableParameters(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual void setFlowsArraySize(size_t size);
    virtual size_t getFlowsArraySize() const;
    virtual const FlowTableEntry& getFlows(size_t k) const;
    virtual FlowTableEntry& getFlowsForUpdate(size_t k) { return const_cast<FlowTableEntry&>(const_cast<FlowTableParameters*>(this)->getFlows(k));}
    virtual void setFlows(size_t k, const FlowTableEntry& flows);
    virtual void insertFlows(size_t k, const FlowTableEntry& flows);
    [[deprecated]] void insertFlows(const FlowTableEntry& flows) {appendFlows(flows);}
    virtual void appendFlows(const FlowTableEntry& flows);
    virtual void eraseFlows(size_t k);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const FlowTableParameters& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, FlowTableParameters& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

template<> inline PollingRequest *fromAnyPtr(any_ptr ptr) { return check_and_cast<PollingRequest*>(ptr.get<cObject>()); }
template<> inline PollingData *fromAnyPtr(any_ptr ptr) { return check_and_cast<PollingData*>(ptr.get<cObject>()); }
inline any_ptr toAnyPtr(const FlowTableEntry *p) {return any_ptr(p);}
template<> inline FlowTableEntry *fromAnyPtr(any_ptr ptr) { return ptr.get<FlowTableEntry>(); }
template<> inline FlowTableParameters *fromAnyPtr(any_ptr ptr) { return check_and_cast<FlowTableParameters*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __POLLINGPACKET_M_H
