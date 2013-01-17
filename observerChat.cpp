// observerChat.cpp : Defines the entry point for the DLL application.
//

#include "bzfsAPI.h"
#include "plugin_utils.h"

class observerChat : public bz_Plugin
{
  virtual const char* Name (){return "SAMPLE PLUGIN";}
  virtual void Init ( const char* config) ;

  virtual void Event ( bz_EventData *eventData );

  const char* variableName = "_observerChat";
  const char* defaultValue = "game";
  const char* permName = "OBSERVERCHAT";
};

BZ_PLUGIN(observerChat)

void observerChat::Init ( const char* commandLine )
{
  int mode = (int)atoi(commandLine);
    const char* variableValue = "";
    if (mode == 0) variableValue = "off"; else
    if (mode == 1) variableValue = "game"; else
    if (mode == 2) variableValue = "alwaysOn"; else {
    if(bz_BZDBItemExists(variableName))
      variableValue = bz_getBZDBString(variableName).c_str();
  }
  bz_setBZDBString(variableName, variableValue);
  bz_debugMessage(0,variableValue);

  bz_debugMessage(4,"observerChat plugin loaded");

  Register(bz_eRawChatMessageEvent);
}

void observerChat::Event ( bz_EventData *eventData )
{
  switch (eventData->eventType)
  {
  case bz_eRawChatMessageEvent:
    {
      bz_ChatEventData_V1 *data = (bz_ChatEventData_V1*)eventData;
      int from = data->from;
      const char* duringTheGame = "";
      
      if (bz_getPlayerTeam(from) != eObservers) return;
      if (data->to != BZ_ALLUSERS) return;
      if (bz_hasPerm(from,permName) || bz_getAdmin(from)) return;
      
      std::string variableValue = makelower(bz_getBZDBString(variableName).c_str());
      if (variableValue == "off" || variableValue == "disable" || variableValue == "disabled" || variableValue == "no") return;
      if (variableValue == "game" || variableValue == "ingame" || variableValue == "countdown" || variableValue == "active") {
        duringTheGame = " during the game."; 
	if (!bz_isCountDownActive()) return;
      } 
            
      bz_sendTextMessagef(BZ_SERVER,from,"You are not allowed to send global messages%s.",duringTheGame);
      bz_sendTextMessagef(BZ_SERVER,from,"Please use observer chat only.");
      data->message = "";
    }
    break;
  default:
    break;
  }
}
// Local Variables: ***
// mode:C++ ***
// tab-width: 8 ***
// c-basic-offset: 2 ***
// indent-tabs-mode: t ***
// End: ***
// ex: shiftwidth=2 tabstop=8
