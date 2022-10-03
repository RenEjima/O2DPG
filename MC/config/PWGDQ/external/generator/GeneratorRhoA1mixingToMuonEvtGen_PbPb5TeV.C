// usage
// o2-sim -j 4 -n 10 -g external  -o sgn  --configKeyValues "GeneratorExternal.fileName=GeneratorCocktailPromptCharmoniaToMuonEvtGen_PbPb5TeV.C;GeneratorExternal.funcName=GeneratorCocktailPromptCharmoniaToMuonEvtGen_PbPb5TeV()"
//
R__ADD_INCLUDE_PATH($O2DPG_ROOT/MC/config/PWGDQ/EvtGen)
R__ADD_INCLUDE_PATH($O2DPG_ROOT/MC/config/PWGDQ/PromptQuarkonia)
#include "GeneratorCocktail.C"
#include "GeneratorEvtGen.C"

namespace o2
{
namespace eventgen
{

class O2_GeneratorParama1p : public GeneratorTGenerator
{

 public:
  O2_GeneratorParama1p() : GeneratorTGenerator("Parama1p")
  {
    parama1p = new GeneratorParam(1, -1, Pta1pPbPb5TeV, Ya1pPbPb5TeV, V2a1pPbPb5TeV, Ipa1pPbPb5TeV);
    parama1p->SetMomentumRange(0., 1.e6);
    parama1p->SetPtRange(0, 999.);
    parama1p->SetYRange(-4.2, -2.3);
    parama1p->SetPhiRange(0., 360.);
    parama1p->SetDecayer(new TPythia6Decayer());
    parama1p->SetForceDecay(kNoDecay); // particle left undecayed
    // - - parama1p->SetTrackingFlag(1);  // (from AliGenParam) -> check this
    setTGenerator(parama1p);
  };

  ~O2_GeneratorParama1p()
  {
    delete parama1p;
  };

  Bool_t Init() override
  {
    GeneratorTGenerator::Init();
    parama1p->Init();
    return true;
  }

  void SetNSignalPerEvent(Int_t nsig) { parama1p->SetNumberParticles(nsig); }

  //-------------------------------------------------------------------------//
  static Double_t Pta1pPbPb5TeV(const Double_t* px, const Double_t* /*dummy*/)
  {
    // mT scaling of Rho pT in pp at 13 TeV for a1, Pythia8
        Double_t x = *px;
        Float_t p0, p1, p2, p3, p4, p5, p6;
        p0 = 1;
        p1 = 0.442572;
        p2 = 3.5986;
        p3 = 0.875139;
        p4 = 10.2394;
        p5 = 1.260;
        p6 = 0.770;
        return p0 * TMath::Sqrt(x*x + p5*p5 - p6*p6) * TMath::Power(x,2.) / TMath::Power(p1 + TMath::Power(x / p2, p3), p4);
  }

  //-------------------------------------------------------------------------//
  static Double_t Ya1pPbPb5TeV(const Double_t* py, const Double_t* /*dummy*/)
  {
    // Use Rho y in pp at 13 TeV instead of a1, Pythia8
        Double_t y = *py;
        Float_t p0, p1;
        p0 = 1;
        p1 = 0.000503187;
        return p0 * exp(-p1 * TMath::Power(y,4.));
  }

  //-------------------------------------------------------------------------//
  static Double_t V2a1pPbPb5TeV(const Double_t* /*dummy*/, const Double_t* /*dummy*/)
  {
    // a1p v2
    return 0.;
  }

  //-------------------------------------------------------------------------//
  static Int_t Ipa1pPbPb5TeV(TRandom*)
  {
    return 20213;
  }

 private:
  GeneratorParam* parama1p = nullptr;
};

class O2_GeneratorParama1m : public GeneratorTGenerator
{

 public:
  O2_GeneratorParama1m() : GeneratorTGenerator("Parama1m")
  {
    parama1m = new GeneratorParam(1, -1, Pta1mPbPb5TeV, Ya1mPbPb5TeV, V2a1mPbPb5TeV, Ipa1mPbPb5TeV);
    parama1m->SetMomentumRange(0., 1.e6);
    parama1m->SetPtRange(0, 999.);
    parama1m->SetYRange(-4.2, -2.3);
    parama1m->SetPhiRange(0., 360.);
    parama1m->SetDecayer(new TPythia6Decayer());
    parama1m->SetForceDecay(kNoDecay); // particle left undecayed
    // - - parama1m->SetTrackingFlag(1);  // check this
    setTGenerator(parama1m);
  };

  ~O2_GeneratorParama1m()
  {
    delete parama1m;
  };

  Bool_t Init() override
  {
    GeneratorTGenerator::Init();
    parama1m->Init();
    return true;
  }

  void SetNSignalPerEvent(Int_t nsig) { parama1m->SetNumberParticles(nsig); }

  //-------------------------------------------------------------------------//
  static Double_t Pta1mPbPb5TeV(const Double_t* px, const Double_t* /*dummy*/)
  {
    // mT scaling of Rho pT in pp at 13 TeV for a1, Pythia8
        Double_t x = *px;
        Float_t p0, p1, p2, p3, p4, p5, p6;
        p0 = 1;
        p1 = 0.442572;
        p2 = 3.5986;
        p3 = 0.875139;
        p4 = 10.2394;
        p5 = 1.260;
        p6 = 0.770;
        return p0 * TMath::Sqrt(x*x + p5*p5 - p6*p6) * TMath::Power(x,2.) / TMath::Power(p1 + TMath::Power(x / p2, p3), p4);
  }

  //-------------------------------------------------------------------------//
  static Double_t Ya1mPbPb5TeV(const Double_t* py, const Double_t* /*dummy*/)
  {
    // Use Rho y in pp at 13 TeV instead of a1, Pythia8
        Double_t y = *py;
        Float_t p0, p1;
        p0 = 1;
        p1 = 0.000503187;
        return p0 * exp(-p1 * TMath::Power(y,4.));
  }

  //-------------------------------------------------------------------------//
  static Double_t V2a1mPbPb5TeV(const Double_t* /*dummy*/, const Double_t* /*dummy*/)
  {
    // a1m v2
    return 0.;
  }

  //-------------------------------------------------------------------------//
  static Int_t Ipa1mPbPb5TeV(TRandom*)
  {
    return -20213;
  }

 private:
  GeneratorParam* parama1m = nullptr;
};

} // namespace eventgen
} // namespace o2

FairGenerator* GeneratorRhoA1mixingToMuonEvtGen_PbPb5TeV()
{

  auto genCocktailEvtGen = new o2::eventgen::GeneratorEvtGen<GeneratorCocktail_class>();

  auto gena1p = new o2::eventgen::O2_GeneratorParama1p;
  gena1p->SetNSignalPerEvent(1); // 1 a1m generated per event by GeneratorParam
  auto gena1m = new o2::eventgen::O2_GeneratorParama1m;
  gena1m->SetNSignalPerEvent(1);               // 1 a1m generated per event by GeneratorParam
  genCocktailEvtGen->AddGenerator(gena1p, 1);
  genCocktailEvtGen->AddGenerator(gena1m, 1);

  TString pdgs = "20213;-20213";
  std::string spdg;
  TObjArray* obj = pdgs.Tokenize(";");
  genCocktailEvtGen->SetSizePdg(obj->GetEntriesFast());
  for (int i = 0; i < obj->GetEntriesFast(); i++) {
    spdg = obj->At(i)->GetName();
    genCocktailEvtGen->AddPdg(std::stoi(spdg), i);
    printf("PDG %d \n", std::stoi(spdg));
  }
  genCocktailEvtGen->SetForceDecay(kEvtDiMuon);

  return genCocktailEvtGen;
}
