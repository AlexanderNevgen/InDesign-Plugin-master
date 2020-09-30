//========================================================================================
//  
//  $File: $
//  
//  Owner: Alexander Nevgen
//  
//  $Author: $
//  
//  $DateTime: $
//  
//  $Revision: $
//  
//  $Change: $
//  
//  Copyright 1997-2012 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================

#include "VCPlugInHeaders.h"

// Interface includes:
#include "ISession.h"
#include "IApplication.h"
#include "IDialogMgr.h"
#include "IDialog.h"
// Dialog-specific resource includes:
#include "CoreResTypes.h"
#include "LocaleSetting.h"
#include "RsrcSpec.h"

// General includes:
#include "CActionComponent.h"
#include "CAlert.h"

// Project includes:
#include "LCID.h"

/** Implements IActionComponent; performs the actions that are executed when the plug-in's
	menu items are selected.

	
	@ingroup linescounter

*/
class LCActionComponent : public CActionComponent
{
public:
/**
 Constructor.
 @param boss interface ptr from boss object on which this interface is aggregated.
 */
		LCActionComponent(IPMUnknown* boss);

		/** The action component should perform the requested action.
			This is where the menu item's action is taken.
			When a menu item is selected, the Menu Manager determines
			which plug-in is responsible for it, and calls its DoAction
			with the ID for the menu item chosen.

			@param actionID identifies the menu item that was selected.
			@param ac active context
			@param mousePoint contains the global mouse location at time of event causing action (e.g. context menus). kInvalidMousePoint if not relevant.
			@param widget contains the widget that invoked this action. May be nil. 
			*/
		virtual void DoAction(IActiveContext* ac, ActionID actionID, GSysPoint mousePoint, IPMUnknown* widget);

	private:
		/** Encapsulates functionality for the about menu item. */
		void DoAbout();
		
		/** Opens this plug-in's dialog. */
		void DoDialog();
		


};

/* CREATE_PMINTERFACE
 Binds the C++ implementation class onto its
 ImplementationID making the C++ code callable by the
 application.
*/
CREATE_PMINTERFACE(LCActionComponent, kLCActionComponentImpl)

/* LCActionComponent Constructor
*/
LCActionComponent::LCActionComponent(IPMUnknown* boss)
: CActionComponent(boss)
{
}

/* DoAction
*/
void LCActionComponent::DoAction(IActiveContext* ac, ActionID actionID, GSysPoint mousePoint, IPMUnknown* widget)
{
	switch (actionID.Get())
	{

		case kLCAboutActionID:
		{
			this->DoAbout();
			break;
		}
					

		case kLCDialogActionID:
		{
			this->DoDialog();
			break;
		}


		default:
		{
			break;
		}
	}
}

/* DoAbout
*/
void LCActionComponent::DoAbout()
{
	CAlert::ModalAlert
	(
		kLCAboutBoxStringKey,				// Alert string
		kOKString, 						// OK button
		kNullString, 						// No second button
		kNullString, 						// No third button
		1,							// Set OK button to default
		CAlert::eInformationIcon				// Information icon.
	);
}



/* DoDialog
*/
void LCActionComponent::DoDialog()
{
	do
	{
		// Get the application interface and the DialogMgr.	
		InterfacePtr<IApplication> application(GetExecutionContextSession()->QueryApplication());
		ASSERT(application);
		if (application == nil) {	
			break;
		}
		InterfacePtr<IDialogMgr> dialogMgr(application, UseDefaultIID());
		ASSERT(dialogMgr);
		if (dialogMgr == nil) {
			break;
		}

		// Load the plug-in's resource.
		PMLocaleId nLocale = LocaleSetting::GetLocale();
		RsrcSpec dialogSpec
		(
			nLocale,					// Locale index from PMLocaleIDs.h. 
			kLCPluginID,			// Our Plug-in ID  
			kViewRsrcType,				// This is the kViewRsrcType.
			kSDKDefDialogResourceID,	// Resource ID for our dialog.
			kTrue						// Initially visible.
		);

		// CreateNewDialog takes the dialogSpec created above, and also
		// the type of dialog being created (kMovableModal).
		IDialog* dialog = dialogMgr->CreateNewDialog(dialogSpec, IDialog::kMovableModal);
		ASSERT(dialog);
		if (dialog == nil) {
			break;
		}

		// Open the dialog.
		dialog->Open(); 
	
	} while (false);			
}
