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

class O2_GeneratorParamRho : public GeneratorTGenerator
{

public:

  O2_GeneratorParamRho() : GeneratorTGenerator("ParamRho") {
    paramRho = new GeneratorParam(1, -1, PtRhoPbPb5TeV, YRhoPbPb5TeV, V2RhoPbPb5TeV, IpRhoPbPb5TeV);
    paramRho->SetMomentumRange(0., 1.e6);
    paramRho->SetPtRange(0, 999.);
    paramRho->SetYRange(-4.2, -2.3);
    paramRho->SetPhiRange(0., 360.);
    paramRho->SetDecayer(new TPythia6Decayer());
    paramRho->SetForceDecay(kNoDecay); // particle left undecayed
    // - - paramRho->SetTrackingFlag(1);  // (from AliGenParam) -> check this
    setTGenerator(paramRho);
  };


  ~O2_GeneratorParamRho() {
    delete paramRho;
  };

  Bool_t Init() override {
    GeneratorTGenerator::Init();
    paramRho->Init();
    return true;
  }

  void SetNSignalPerEvent(Int_t nsig){paramRho->SetNumberParticles(nsig);}

  //-------------------------------------------------------------------------//
  static Double_t PtRhoPbPb5TeV(const Double_t *px, const Double_t * /*dummy*/)
  {
  	// Rho pT in PbPb at 5 TeV, Pythia8HI
	Double_t x=*px;
	Float_t p0,p1,p2,p3,p4;
	p0 = 1.;
	p1 = 0.512514;
	p2 = 1.11739;
	p3 = 1.88096;
  p4 = 2.43008;
	return p0 * TMath::Power(x,2.) / TMath::Power(p1 + TMath::Power(x / p2, p3), p4);
  }

  //-------------------------------------------------------------------------//
  static Double_t YRhoPbPb5TeV(const Double_t *py, const Double_t * /*dummy*/)
  {
  	// Rho y in pp at 5 TeV, Pythia8HI
	Double_t y = *py;
	Float_t p0,p1,p2;
	p0 = 1.;
	p1 = 0.000811946;
	p2 = -0.00544095;
	return p0 * exp(-p1 * TMath::Power(y,4.) + p2 * TMath::Power(y,2.));
  }

  //-------------------------------------------------------------------------//
  static Double_t V2RhoPbPb5TeV(const Double_t * /*dummy*/, const Double_t * /*dummy*/)
  {
        //rho v2
        return 0.;
  }

  //-------------------------------------------------------------------------//
  static Int_t IpRhoPbPb5TeV(TRandom *)
  {
        return 113;
  }


private:

  GeneratorParam *paramRho = nullptr;

};

class O2_GeneratorParamOmega : public GeneratorTGenerator
{

public:

  O2_GeneratorParamOmega() : GeneratorTGenerator("ParamOmega") {
    paramOmega = new GeneratorParam(1, -1, PtOmegaPbPb5TeV, YOmegaPbPb5TeV, V2OmegaPbPb5TeV, IpOmegaPbPb5TeV);
    paramOmega->SetMomentumRange(0., 1.e6);
    paramOmega->SetPtRange(0, 999.);
    paramOmega->SetYRange(-4.2, -2.3);
    paramOmega->SetPhiRange(0., 360.);
    paramOmega->SetDecayer(new TPythia6Decayer());
    paramOmega->SetForceDecay(kNoDecay); // particle left undecayed
    // - - paramOmega->SetTrackingFlag(1);  // check this
    setTGenerator(paramOmega);
  };

  ~O2_GeneratorParamOmega() {
    delete paramOmega;
  };

  Bool_t Init() override {
    GeneratorTGenerator::Init();
    paramOmega->Init();
    return true;
  }

  void SetNSignalPerEvent(Int_t nsig){paramOmega->SetNumberParticles(nsig);}

  //-------------------------------------------------------------------------//
  static Double_t PtOmegaPbPb5TeV(const Double_t *px, const Double_t * /*dummy*/)
  {
  	// Omega pT in PbPb at 5 TeV, Pythia8HI
	Double_t x=*px;
	Float_t p0,p1,p2,p3,p4;
	p0 = 1.;
	p1 = 0.826671;
	p2 = 0.975843;
	p3 = 1.77957;
  p4 = 2.85792;
	return p0 * TMath::Power(x,2.) / TMath::Power(p1 + TMath::Power(x / p2, p3), p4);
  }

  //-------------------------------------------------------------------------//
  static Double_t YOmegaPbPb5TeV(const Double_t *py, const Double_t * /*dummy*/)
  {
  	// Omega y in PbPb at 5 TeV, Pythia8HI
	Double_t y = *py;
	Float_t p0,p1,p2;
	p0 = 1.;
	p1 = 0.000789404;
	p2 = -0.00725840;
	return p0 * exp(-p1 * TMath::Power(y,4.) + p2 * TMath::Power(y,2.));
  }

  //-------------------------------------------------------------------------//
  static Double_t V2OmegaPbPb5TeV(const Double_t * /*dummy*/, const Double_t * /*dummy*/)
  {
        //omega v2
        return 0.;
  }

  //-------------------------------------------------------------------------//
  static Int_t IpOmegaPbPb5TeV(TRandom *)
  {
        return 223;
  }


private:

  GeneratorParam *paramOmega = nullptr;

};

class O2_GeneratorParamPhi : public GeneratorTGenerator
{

public:

  O2_GeneratorParamPhi() : GeneratorTGenerator("ParamPhi") {
    paramPhi = new GeneratorParam(1, -1, PtPhiPbPb5TeV, YPhiPbPb5TeV, V2PhiPbPb5TeV, IpPhiPbPb5TeV);
    paramPhi->SetMomentumRange(0., 1.e6);
    paramPhi->SetPtRange(0, 999.);
    paramPhi->SetYRange(-4.2, -2.3);
    paramPhi->SetPhiRange(0., 360.);
    paramPhi->SetDecayer(new TPythia6Decayer());
    paramPhi->SetForceDecay(kNoDecay); // particle left undecayed
    // - - paramPhi->SetTrackingFlag(1);  // check this
    setTGenerator(paramPhi);
  };

  ~O2_GeneratorParamPhi() {
    delete paramPhi;
  };

  Bool_t Init() override {
    GeneratorTGenerator::Init();
    paramPhi->Init();
    return true;
  }

  void SetNSignalPerEvent(Int_t nsig){paramPhi->SetNumberParticles(nsig);}

  //-------------------------------------------------------------------------//
  static Double_t PtPhiPbPb5TeV(const Double_t *px, const Double_t * /*dummy*/)
  {
  	// Phi pT in PbPb at 5 TeV, Pythia8HI
	Double_t x=*px;
	Float_t p0,p1,p2,p3,p4;
	p0 = 1.;
	p1 = 0.907455;
	p2 = 0.945388;
	p3 = 1.71594;
  p4 = 2.50996;
	return p0 * TMath::Power(x,2.) / TMath::Power(p1 + TMath::Power(x / p2, p3), p4);
  }

  //-------------------------------------------------------------------------//
  static Double_t YPhiPbPb5TeV(const Double_t *py, const Double_t * /*dummy*/)
  {
  	// Phi y in PbPb at 5 TeV, Pythia8HI
	Double_t y = *py;
	Float_t p0,p1,p2;
	p0 = 1.;
	p1 = 0.00134533;
	p2 = -0.000644004;
	return p0 * exp(-p1 * TMath::Power(y,4.) + p2 * TMath::Power(y,2.));
  }

  //-------------------------------------------------------------------------//
  static Double_t V2PhiPbPb5TeV(const Double_t * /*dummy*/, const Double_t * /*dummy*/)
  {
        //phi v2
        return 0.;
  }

  //-------------------------------------------------------------------------//
  static Int_t IpPhiPbPb5TeV(TRandom *)
  {
        return 333;
  }


private:

  GeneratorParam *paramPhi = nullptr;

};

} // namespace eventgen
} // namespace o2

FairGenerator* GeneratorRhoA1mixingToMuonEvtGen_PbPb5TeV()
{

  auto genCocktailEvtGen = new o2::eventgen::GeneratorEvtGen<GeneratorCocktail_class>();

  auto gena1p = new o2::eventgen::O2_GeneratorParama1p;
  gena1p->SetNSignalPerEvent(5); // 1 a1m generated per event by GeneratorParam
  auto gena1m = new o2::eventgen::O2_GeneratorParama1m;
  gena1m->SetNSignalPerEvent(5); // 1 a1m generated per event by GeneratorParam
  genCocktailEvtGen->AddGenerator(gena1p, 1);
  genCocktailEvtGen->AddGenerator(gena1m, 1);

  auto genRho = new o2::eventgen::O2_GeneratorParamRho;
  genRho->SetNSignalPerEvent(530); // 4 Rho generated per event by GeneratorParam
  auto genOmega = new o2::eventgen::O2_GeneratorParamOmega;
  genOmega->SetNSignalPerEvent(420);  // 2 Omega generated per event by GeneratorParam
  auto genPhi = new o2::eventgen::O2_GeneratorParamPhi;
  genPhi->SetNSignalPerEvent(23);  // 2 Phi generated per event by GeneratorParam
  genCocktailEvtGen->AddGenerator(genRho,1); // 2/3 Rho
  genCocktailEvtGen->AddGenerator(genOmega,1);  // 1/3 Omega
  genCocktailEvtGen->AddGenerator(genPhi,1);  // 1/3 Phi

  TString pdgs = "20213;-20213;113;233;333";
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
