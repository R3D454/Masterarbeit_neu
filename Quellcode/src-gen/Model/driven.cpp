// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define Model_driven_BODY

/************************************************************
 driven class body
 ************************************************************/

// include associated header file
#include "Model/driven.h"
// Derived includes directives
namespace Articulation
   {
      enum Motion
      {
         AZIMUTH = 11,
         AZIMUTH_RATE = 12,
         ELEVATION = 13,
         POSITION = 1
      };

      enum Part
      {
         PRIMARY_TURRET = 4096,
         PRIMARY_GUN = 4416,
         SECONDARY_GUN = 6016,
				 PRIMARY_LAUNCHER = 4736,
				 PRIMARY_RADAR = 5376,
         SECONDARY_RADAR = 6976
       };

      enum Designator
      {
         ARTICULATED = 0,
         ATTACHED = 1
      };
   }
namespace Model {

// static attributes (if any)
Geodesic geod(Constants::WGS84_a(), Constants::WGS84_f());

/**
 *
 * @return
 */
std::string driven::getCategory() {
return Category;
}

/**
 *
 * @param name
 */
void driven::setCategory(std::string /*in*/name) {
Category = name;
}

/**
 *
 */
void driven::rmAllEquipment() {
}

/**
 *
 * @param velocity
 */
void driven::setVelo(double/*in*/ x,double/*in*/ y,double/*in*/ z) {
Velocity.x = x;
Velocity.y = y;
Velocity.z = z;
}

/**
 *
 * @return velocity
 */
Vector3D driven::getVelo() {
return Velocity;
}

/**
 *
 * @param orientation
 */
void driven::setOrientation(double/*in*/ x,double/*in*/ y,double/*in*/ z) {
Orientation.x = x;
Orientation.y = y;
Orientation.z = z;
}

/**
 *
 * @return orientation
 */
Vector3D driven::getOrientation() {
  return Orientation;
}

/**
 *
 * @return
 */
std::string driven::getSubCategory() {
  return SubCategory;
}

/**
 *
 * @param name
 */
void driven::setSubCategory(std::string /*in*/sub) {
  SubCategory = sub;

}

/**
 *
 * @param type
 */
void driven::setType(std::string /*in*/type) {
  Type = type;
}

/**
 *
 * @return type
 */
std::string driven::getType() {
  return Type;
}

void driven::printInfo(){

}

 void driven::getDIS_PDUType(std::string kind, std::string domain , std::string country , std::string category,  std::string subcategory) {

DIS_EntityType_Variables EntityType;
Model::DIS_enum convert;

// std::cout << kind<<domain<<country<<category<<subcategory << '\n';

 EntityType =  convert.getDISEntityType(kind, domain ,country , category,  subcategory,  "todo",  "todo");

 // std::cout << EntityType.Kind<<" " << EntityType.Domain<<" " << EntityType.Country<<" " <<EntityType.Category<<" " <<EntityType.SubCategory <<'\n';

object::setDIS_EntityType_Variables(EntityType);



 }

 void driven::createDISPDU(){
   driven::getDIS_PDUType(object::getKind(), object::getDomain() , object::getCountry() , Category,  SubCategory);
   driven::makeDISArticulationsParameter();
   DIS::Vector3Float velo;
   velo.setX(Velocity.x);
   velo.setY(Velocity.y);
   velo.setZ(Velocity.z);
   DIS::Orientation orie;
   orie.setTheta(Orientation.x);
   orie.setPsi(Orientation.y);
   orie.setPhi(Orientation.z);
   object::makeStdDISPDU(velo, orie);



 }
 void driven::setEquipment(Equipment *eq){
   equipment = eq;
 }

 Equipment* driven::getEquipment(){
   return equipment;
 }

 void driven::makeDISArticulationsParameter(){

   if (equipment !=NULL) {

   std::list<Model::weapon*> weapon = 	equipment->getWeapon();
   std::list<Model::sensor*> sensor = equipment->getSensor();
   // DIS::ArticulationParameter DISequipment[(weapon.size()+sensor.size())];
   std::list<DIS::ArticulationParameter>  paramList;
   std::vector<DIS::ArticulationParameter> params;
   params.clear();
   params.resize(3);
    int i = 0;
    int amountTurrents = 0;
    int amountLauncher = 0;
    int amountRadars = 0;
    int amountSonar = 0;

   for(std::list<Model::weapon*>::iterator it=weapon.begin(); it != weapon.end(); it++)
     {
       // std::cout << (*it)->getType() << '\n';
        if((*it)->getType()=="PRIMARY_TURRET"){
          DIS::ArticulationParameter DISequipment[3];
          DISequipment[1].setParameterType(DIS::Convert::MakeArticulationParameterType(Articulation::PRIMARY_TURRET+amountTurrents*32,Articulation::AZIMUTH));
          DISequipment[1].setPartAttachedTo( 0 );
          DISequipment[1].setParameterTypeDesignator(Articulation::ARTICULATED );
          DISequipment[1].setParameterValue((*it)->getGunValues().Orientation);
          paramList.push_back(DISequipment[1]);

          DISequipment[2].setParameterType(DIS::Convert::MakeArticulationParameterType(Articulation::PRIMARY_TURRET+amountTurrents*32,Articulation::AZIMUTH_RATE));
          DISequipment[2].setPartAttachedTo( 0 );
          DISequipment[2].setParameterTypeDesignator(Articulation::ARTICULATED );
          DISequipment[2].setParameterValue((*it)->getGunValues().Orientation);
          paramList.push_back(DISequipment[2]);

          DISequipment[3].setParameterType(DIS::Convert::MakeArticulationParameterType(Articulation::PRIMARY_GUN,Articulation::ELEVATION));
          DISequipment[3].setPartAttachedTo( 1 );
          DISequipment[3].setParameterTypeDesignator(Articulation::ARTICULATED );
          DISequipment[3].setParameterValue((*it)->getGunValues().Elevation);

          paramList.push_back(DISequipment[3]);
          amountTurrents++;
        } else if ((*it)->getType()=="VLS") {
          DIS::ArticulationParameter DISequipment;
          DISequipment.setParameterType(DIS::Convert::MakeArticulationParameterType(Articulation::PRIMARY_LAUNCHER+amountLauncher*32,Articulation::AZIMUTH));
          DISequipment.setPartAttachedTo( 0 );
          DISequipment.setParameterTypeDesignator(Articulation::ARTICULATED );
          DISequipment.setParameterValue(0);
          paramList.push_back(DISequipment);
          amountLauncher++;
        } else{

        }

        }
        for(std::list<Model::sensor*>::iterator it=sensor.begin(); it != sensor.end(); it++)
          {
            // std::cout << (*it)->getType() << '\n';
             if((*it)->getType()=="RADAR"){
               DIS::ArticulationParameter DISequipment[1];
               DISequipment[1].setParameterType(DIS::Convert::MakeArticulationParameterType(Articulation::PRIMARY_RADAR+amountRadars*32,Articulation::POSITION));
               DISequipment[1].setPartAttachedTo( 0 );
               DISequipment[1].setParameterTypeDesignator(Articulation::ARTICULATED );
               DISequipment[1].setParameterValue(0);
               paramList.push_back(DISequipment[1]);

               // DISequipment[2].setParameterType(DIS::Convert::MakeArticulationParameterType(Articulation::PRIMARY_TURRET,Articulation::AZIMUTH_RATE));
               // DISequipment[2].setPartAttachedTo( 0 );
               // DISequipment[2].setParameterTypeDesignator(Articulation::ARTICULATED );
               // DISequipment[2].setParameterValue( 0 );
               // paramList.push_back(DISequipment[2]);
               //
               // DISequipment[3].setParameterType(DIS::Convert::MakeArticulationParameterType(Articulation::PRIMARY_TURRET,Articulation::ELEVATION));
               // DISequipment[3].setPartAttachedTo( 1 );
               // DISequipment[3].setParameterTypeDesignator(Articulation::ARTICULATED );
               // DISequipment[3].setParameterValue(0);
               // paramList.push_back(DISequipment[3]);
               amountRadars++;
             } else if ((*it)->getType()=="SONAR") {
               DIS::ArticulationParameter DISequipment;
               DISequipment.setParameterType(DIS::Convert::MakeArticulationParameterType(Articulation::SECONDARY_RADAR+amountSonar*32,Articulation::POSITION));
               DISequipment.setPartAttachedTo( 0 );
               DISequipment.setParameterTypeDesignator(Articulation::ARTICULATED );
               DISequipment.setParameterValue(0);
               paramList.push_back(DISequipment);
               amountSonar++;
             }

             }


        params.resize(paramList.size());
        for (std::list<DIS::ArticulationParameter> ::iterator it=paramList.begin(); it != paramList.end(); ++it){
          params[i] = *it;
          i++;
     }
     object::addArticulationParameter(params);
   } else {

   }
 }

 void driven::updateObject(double dt){
   position_dec position = object::getPosition();
   Vector3D orientation = driven::getOrientation();
   Vector3D velocity = driven::getVelo();
   position_dec newPosition;

   geod.Direct(position.lat,position.lon,orientation.x,velocity.x*dt,newPosition.lat,newPosition.lon);

   object::setPosition(newPosition.lat,newPosition.lon,position.height_above_geoid);
   // std::list<Model::weapon*> weapon = 	equipment->getWeapon();
   // // std::list<Model::sensor*> sensor = equipment->getSensor();
   //
   // for(std::list<Model::weapon*>::iterator it=weapon.begin(); it != weapon.end(); it++)
   //   {
   //    (*it)->moveGuns(1,1,0.5);
   //   }

 }

} // of namespace Model

/************************************************************
 End of driven class body
 ************************************************************/