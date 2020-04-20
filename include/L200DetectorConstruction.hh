#ifndef L200DetectorConstruction_h
#define L200DetectorConstruction_h

#include "G4VUserDetectorConstruction.hh"
#include "G4Material.hh"
#include "G4RotationMatrix.hh"
#include "Randomize.hh"
#include "globals.hh"

#include "L200DetectorMessenger.hh"



class G4VPhysicalVolume;
class G4LogicalVolume;
class L200DetectorMessenger;

class L200DetectorConstruction : public G4VUserDetectorConstruction{

public:
    	L200DetectorConstruction();
    	virtual ~L200DetectorConstruction();

	//wird vom RunManager aufgerufen bei der initialisation und rebuild
	virtual G4VPhysicalVolume* Construct();//mit aufräumen

	//wird von Construct() bei initialisation und rebuild aufgerufen
	G4VPhysicalVolume* ConstructDetector();//ohne aufräumen

	//wird von Construct() bei initialisation aufgerufen.
	void InitializeMaterials();//einmalig ausgeführt.

	//wird vom Konstruktor aufgerufen
	void InitializeDimensions();//einmalig ausgeführt.

	//wird vom Konstruktor aufgerufen
	void InitializeRotations();//einmalig ausgeführt.

    	//Für die Hit-Generation über die eingebaute Funktionalität von G4VSensitiveDetector
    	//I think we rather distinguish our sensitive volume by hand in our
    	//L1kSteppingAction
	virtual void ConstructSDandField();

    	void UpdateGeometry();

    	//Messenger functions
    	void setinnerShroudInnerR(G4double value){innerShroudInnerR = value;}
	void setinnerShroudOuterR(G4double value){innerShroudOuterR = value;}
	void setouterShroudInnerR(G4double value){outerShroudInnerR = value;}
	void setouterShroudOuterR(G4double value){outerShroudOuterR = value;}
	void setwlsrRadius(G4double value){wlsrRadius = value;}
	void setinnerShroudHeight(G4double value){innerShroudHeight = value;}
	void setouterShroudHeight(G4double value){outerShroudHeight = value;}
	void setwlsrHeight(G4double value){wslrHeight = value;}
	void setwlsrTPBThickness(G4double value){wslrTPBThickness = value;}
	void setwlsrCuThickness(G4double value){wlsrCuThickness = value;}
	void setwlsrTetraTexThickness(G4double value){wlsrTetraTexThickness = value;}
	void setcryostatWallThickness(G4double value){wallthickness = value;}
	void setlArAbsVUV(G4double value){lArAbsVUV = value;}
	void setlArAbsVis(G4double value){lArAbsVis = value;}
	void setlArWL(G4double value){lArWL = value;}
	void settpbWL(G4double value){tpbWL = value;}


protected:
	G4VPhysicalVolume* worldPhys;
	G4VPhysicalVolume* cryostatPhys;
	G4VPhysicalVolume* fiberShroudInnerPhys;
	G4VPhysicalVolume* fiberShroudOuterPhys;
	G4VPhysicalVolume* lArPhys;
	G4VPhysicalVolume* wslrCopperPhys;
	G4VPhysicalVolume* wslrTetraTexPhys;
	G4VPhysicalVolume* wslrTPBPhys;

	//Materialien:
	G4Material* world_mat;
	G4Material* copper_mat;
	G4Material* lAr_mat;
	G4Material* tetraTex_mat;
	G4Material* steel_mat;
	G4Material* TPB_mat;

	//Optical properties
	G4double LArAttVUV;

	//primäre Dimensionen (zwischenwerte werden in CostructDetector() angelegt und berechnet)
	//alle Längen sind NICHT halbiert
	G4double world_len, world_wid, world_height;//Längen Welt (in x, y, z)

	//For cryostat design
	G4double hneck;
   	G4double htopcylbot;
   	G4double hlittlecyl;
   	G4double slopetoplid;
   	G4double slopebotlid;

   	G4double rneck;
  	G4double rcyl;
   	G4double rlittlecyl;
   	G4double wallthickness;

	//for the inner fiber shroud
	G4double innerShroudInnerR;
	G4double innerShroudOuterR;
	G4double innerShroudHeight;

	//for the outer fiber shroud
	G4double outerShroudInnerR;
	G4double outerShroudOuterR;
	G4double outerShroudHeight;

	//for WSLR
	G4double wslrCopperInnerR;
	G4double wslrCopperOuterR;
	G4double wlsrRadius;
	G4double wslrTetraTexInnerR;
	G4double wslrTetraTexOuterR;
	G4double wslrTPBThickness;
	G4double wlsrCuThickness;
	G4double wlsrTetraTexThickness;
	G4double wslrHeight;

	//optical stuff
	G4double lambdaE;
	G4double lArAbsVUV;
	G4double lArAbsVis;
	G4double lArWL;
	G4double tpbWL;

	//Messenger
	L200DetectorMessenger* det_briefTaube;

	void ConstructCryostat();
	void FillLAr();
	void BuildInnerShroud();
	void BuildOuterShroud();
	void BuildWSLRCopper();
	void BuildWSLRTetra();
	void BuildWSLRTPB();
	//void BuildWSLRChimney();
	void BuildOptics();


	//optical functions
	G4double LArRefIndex(G4double lambda);
	G4double LArEpsilon(G4double lambda);
	G4double LArRayLength(G4double lambda, G4double temp);
};

#endif















