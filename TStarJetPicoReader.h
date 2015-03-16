#ifndef __TSTARJETPICOREADER_HH
#define __TSTARJETPICOREADER_HH

#include <TObject.h>
#include <TString.h>
#include "TStarJetVectorContainer.h"

class TStarJetPicoEventCuts;
class TStarJetPicoPrimaryTrack;
class TStarJetPicoTower;
class TStarJetPicoV0;
class TStarJetPicoV0Cuts;
class TStarJetPicoTriggerInfo;
class TStarJetPicoTrackCuts;
class TStarJetPicoTowerCuts;

class TChain;
class TBranch;
class TArrayI;
class TList;
class TStopwatch;

#include "TStarJetPicoReaderBase.h"

class TStarJetPicoReader : public TStarJetPicoReaderBase
{
 public:

  TStarJetPicoReader();
  virtual ~TStarJetPicoReader();

  TStarJetPicoEventCuts* GetEventCuts() {return fEventCuts;}
  TStarJetPicoTrackCuts* GetTrackCuts() {return fTrackCuts;}
  TStarJetPicoTowerCuts* GetTowerCuts() {return fTowerCuts;}
  TStarJetPicoV0Cuts*    GetV0Cuts()    {return fV0Cuts;}

  void SetRejectTowerElectrons(Bool_t val) {fRejectTowerElectrons = val;}
  void SetApplyMIPCorrection(Bool_t val);
  void SetApplyFractionHadronicCorrection(Bool_t val);
  void SetFractionHadronicCorrection(Double_t val);

  virtual void SetEventCuts(TStarJetPicoEventCuts* evCuts);
  virtual void SetTrackCuts(TStarJetPicoTrackCuts* trCuts);
  virtual void SetTowerCuts(TStarJetPicoTowerCuts* twCuts);
  virtual void SetV0Cuts(TStarJetPicoV0Cuts* v0Cuts);

 protected:
  
  virtual Bool_t LoadEvent();
  virtual Bool_t LoadV0s(TArrayI *trackIdsToRemove);
  virtual Bool_t LoadTracks(TArrayI *trackIdsToRemove);
  virtual Bool_t LoadTowers();

 private:

  TStarJetPicoEventCuts* fEventCuts; //! cuts for event selection
  TStarJetPicoTrackCuts* fTrackCuts;//! cuts tracks
  TStarJetPicoTowerCuts* fTowerCuts;//! cuts tower
  TStarJetPicoV0Cuts*    fV0Cuts;//! cuts for V0s

  Bool_t   fRejectTowerElectrons; // Make sure we do not double count the electrons.
  Bool_t   fApplyMIPCorrection; // Apply MIP or not? Exclusive with fApplyFractionHadronicCorrection
  Bool_t   fApplyFractionHadronicCorrection; // Another type of charge particles energy depostion in EMC.
  Double_t fFractionHadronicCorrection; // Fraction of momentum of the TPC track to be subtracted from EMC tower.
  
  ClassDef(TStarJetPicoReader, 1)
};

#endif
