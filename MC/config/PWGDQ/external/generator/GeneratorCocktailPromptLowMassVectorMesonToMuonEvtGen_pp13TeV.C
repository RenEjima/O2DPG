// usage
// o2-sim -j 4 -n 10 -g external  -o sgn  --configKeyValues "GeneratorExternal.fileName=GeneratorCocktailPromptCharmoniaToMuonEvtGen_pp13TeV.C;GeneratorExternal.funcName=GeneratorCocktailPromptCharmoniaToMuonEvtGen_pp13TeV()"
//
R__ADD_INCLUDE_PATH($O2DPG_ROOT/MC/config/PWGDQ/EvtGen)
R__ADD_INCLUDE_PATH($O2DPG_ROOT/MC/config/PWGDQ/PromptQuarkonia)
#include "GeneratorCocktail.C"
#include "GeneratorEvtGen.C"

namespace o2 {
namespace eventgen {

class O2_GeneratorParamRho : public GeneratorTGenerator
{

public:

  O2_GeneratorParamRho() : GeneratorTGenerator("ParamRho") {
    paramRho = new GeneratorParam(1, -1, PtRhopp13TeV, YRhopp13TeV, V2Rhopp13TeV, IpRhopp13TeV);
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
  static Double_t PtRhopp13TeV(const Double_t *px, const Double_t * /*dummy*/)
  {
        // Rho pT in pp at 13 TeV, Pythia8
        Double_t x = *px;
        Float_t p0, p1, p2, p3, p4;
        p0 = 1;
        p1 = 0.442572;
        p2 = 3.5986;
        p3 = 0.875139;
        p4 = 10.2394;
        return p0 * TMath::Power(x,2.) / TMath::Power(p1 + TMath::Power(x / p2, p3), p4);
  }

  //-------------------------------------------------------------------------//
  static Double_t YRhopp13TeV(const Double_t *py, const Double_t * /*dummy*/)
  {
        // Rho y in pp at 13 TeV, Pythia8
        Double_t y = *py;
        Float_t p0, p1;
        p0 = 1;
        p1 = 0.000503187;
        return p0 * exp(-p1 * TMath::Power(x,4.));
  }

  //-------------------------------------------------------------------------//
  static Double_t V2Rhopp13TeV(const Double_t * /*dummy*/, const Double_t * /*dummy*/)
  {
        //Rho v2
        return 0.;
  }

  //-------------------------------------------------------------------------//
  static Int_t IpRhopp13TeV(TRandom *)
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
    paramOmega = new GeneratorParam(1, -1, PtOmegapp13TeV, YOmegapp13TeV, V2Omegapp13TeV, IpOmegapp13TeV);
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
  static Double_t PtOmegapp13TeV(const Double_t *px, const Double_t * /*dummy*/)
  {
        // Omega pT in pp at 13 TeV, Pythia8
        Double_t x = *px;
        Float_t p0, p1, p2, p3, p4;
        p0 = 1;
        p1 = 0.376274;
        p2 = 3.86097;
        p3 = 0.904797;
        p4 = 9.70109;
        return p0 * TMath::Power(x,2.) / TMath::Power(p1 + TMath::Power(x / p2, p3), p4);
  }

  //-------------------------------------------------------------------------//
  static Double_t YOmegapp13TeV(const Double_t *py, const Double_t * /*dummy*/)
  {
        // Omega y in pp at 13 TeV, Pythia8
        Double_t y = *py;
        Float_t p0, p1;
        p0 = 1;
        p1 = 0.000508055;
        return p0 * exp(-p1 * TMath::Power(x,4.));
  }

  //-------------------------------------------------------------------------//
  static Double_t V2Omegapp13TeV(const Double_t * /*dummy*/, const Double_t * /*dummy*/)
  {
        //Omega v2
        return 0.;
  }

  //-------------------------------------------------------------------------//
  static Int_t IpOmegapp13TeV(TRandom *)
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
    paramPhi = new GeneratorParam(1, -1, PtPhipp13TeV, YPhipp13TeV, V2Phipp13TeV, IpPhipp13TeV);
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
  static Double_t PtPhipp13TeV(const Double_t *px, const Double_t * /*dummy*/)
  {
        // Phi pT in pp at 13 TeV, Pythia8
        Double_t x = *px;
        Float_t p0, p1, p2, p3, p4;
        p0 = 1;
        p1 = 0.619994;
        p2 = 5.03561;
        p3 = 0.739176;
        p4 = 14.1466;
        return p0 * TMath::Power(x,2.) / TMath::Power(p1 + TMath::Power(x / p2, p3), p4);
  }

  //-------------------------------------------------------------------------//
  static Double_t YPhipp13TeV(const Double_t *py, const Double_t * /*dummy*/)
  {
        // Phi y in pp at 13 TeV, Pythia8
        Double_t y = *py;
        Float_t p0, p1;
        p0 = 1;
        p1 = 0.000715295;
        return p0 * exp(-p1 * TMath::Power(x,4.));
  }

  //-------------------------------------------------------------------------//
  static Double_t V2Phipp13TeV(const Double_t * /*dummy*/, const Double_t * /*dummy*/)
  {
        //Phi v2
        return 0.;
  }

  //-------------------------------------------------------------------------//
  static Int_t IpPhipp13TeV(TRandom *)
  {
        return 333;
  }


private:

  GeneratorParam *paramPhi = nullptr;

};

}}


FairGenerator* GeneratorCocktailPromptLowMassVectorMesonToMuonEvtGen_pp13TeV()
{

  auto genCocktailEvtGen = new o2::eventgen::GeneratorEvtGen<GeneratorCocktail_class>();

  auto genRho = new o2::eventgen::O2_GeneratorParamRho;
  genRho->SetNSignalPerEvent(4); // 4 Rho generated per event by GeneratorParam
  auto genOmega = new o2::eventgen::O2_GeneratorParamOmega;
  genOmega->SetNSignalPerEvent(2);  // 2 Omega generated per event by GeneratorParam
  auto genPhi = new o2::eventgen::O2_GeneratorParamPhi;
  genPhi->SetNSignalPerEvent(2);  // 2 Phi generated per event by GeneratorParam
  genCocktailEvtGen->AddGenerator(genRho,1); // 2/3 Rho
  genCocktailEvtGen->AddGenerator(genOmega,1);  // 1/3 Omega
  genCocktailEvtGen->AddGenerator(genPhi,1);  // 1/3 Phi


  TString pdgs = "113;223;333";
  std::string spdg;
  TObjArray *obj = pdgs.Tokenize(";");
  genCocktailEvtGen->SetSizePdg(obj->GetEntriesFast());
  for(int i=0; i<obj->GetEntriesFast(); i++) {
   spdg = obj->At(i)->GetName();
   genCocktailEvtGen->AddPdg(std::stoi(spdg),i);
   printf("PDG %d \n",std::stoi(spdg));
  }
  genCocktailEvtGen->SetForceDecay(kEvtDiMuon);

  return genCocktailEvtGen;
}
