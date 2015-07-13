/**********************************************************************

  Audacity: A Digital Audio Editor

  VSTControl.h

  Leland Lucius

**********************************************************************/

#ifndef AUDACITY_VSTCONTROL_H
#define AUDACITY_VSTCONTROL_H

#include <wx/control.h>

#include "aeffectx.h"

class VSTEffectLink
{
public:
   virtual ~VSTEffectLink() {};
   virtual intptr_t callDispatcher(int opcode, int index, intptr_t value, void *ptr, float opt) = 0;
};

class VSTControlBase : public wxControl
{
public:
   VSTControlBase()
   {
   }

   virtual ~VSTControlBase()
   {
   }

   virtual bool Create(wxWindow *parent, VSTEffectLink *link)
   {
      mParent = parent;
      mLink = link;
   
      DontCreatePeer();
   
      if (!wxControl::Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxEmptyString))
      {
         return false;
      }

      return true;
   }
   
protected:
   wxWindow *mParent;
   VSTEffectLink *mLink;
};

#if defined(__WXMAC__)
#include "VSTControlMac.h"
#elif defined(__WXMSW__)
#include "VSTControlMSW.h"
#elif defined(__WXGTK__)
#include "VSTControlGTK.h"
#endif

#endif