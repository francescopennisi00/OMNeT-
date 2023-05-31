//
// Generated file, do not edit! Created by opp_msgtool 6.0 from ApplicationPacket.msg.
//

#ifndef __APPLICATIONPACKET_M_H
#define __APPLICATIONPACKET_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

class DataPacket;
class DataControlInfo;
/**
 * Class generated from <tt>ApplicationPacket.msg:1</tt> by opp_msgtool.
 * <pre>
 * packet DataPacket
 * {
 *     simtime_t genTime; //istante di generazione del pacchetto
 *     bool lastBurstPacket = false; //di default il pacchetto non e' l'ultimo del burst
 *     uint64_t seqno; //numero di sequenza
 * }
 * </pre>
 */
class DataPacket : public ::omnetpp::cPacket
{
  protected:
    omnetpp::simtime_t genTime = SIMTIME_ZERO;
    bool lastBurstPacket = false;
    uint64_t seqno = 0;

  private:
    void copy(const DataPacket& other);

  protected:
    bool operator==(const DataPacket&) = delete;

  public:
    DataPacket(const char *name=nullptr, short kind=0);
    DataPacket(const DataPacket& other);
    virtual ~DataPacket();
    DataPacket& operator=(const DataPacket& other);
    virtual DataPacket *dup() const override {return new DataPacket(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual omnetpp::simtime_t getGenTime() const;
    virtual void setGenTime(omnetpp::simtime_t genTime);

    virtual bool getLastBurstPacket() const;
    virtual void setLastBurstPacket(bool lastBurstPacket);

    virtual uint64_t getSeqno() const;
    virtual void setSeqno(uint64_t seqno);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const DataPacket& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, DataPacket& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ApplicationPacket.msg:8</tt> by opp_msgtool.
 * <pre>
 * //informazioni di controllo immesse dall'applicazione
 * message DataControlInfo
 * {
 *     string destination;
 * }
 * </pre>
 */
class DataControlInfo : public ::omnetpp::cMessage
{
  protected:
    omnetpp::opp_string destination;

  private:
    void copy(const DataControlInfo& other);

  protected:
    bool operator==(const DataControlInfo&) = delete;

  public:
    DataControlInfo(const char *name=nullptr, short kind=0);
    DataControlInfo(const DataControlInfo& other);
    virtual ~DataControlInfo();
    DataControlInfo& operator=(const DataControlInfo& other);
    virtual DataControlInfo *dup() const override {return new DataControlInfo(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const char * getDestination() const;
    virtual void setDestination(const char * destination);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const DataControlInfo& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, DataControlInfo& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

template<> inline DataPacket *fromAnyPtr(any_ptr ptr) { return check_and_cast<DataPacket*>(ptr.get<cObject>()); }
template<> inline DataControlInfo *fromAnyPtr(any_ptr ptr) { return check_and_cast<DataControlInfo*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __APPLICATIONPACKET_M_H

