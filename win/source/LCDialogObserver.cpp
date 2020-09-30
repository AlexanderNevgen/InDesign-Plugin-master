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
#include "IControlView.h"
#include "IPanelControlData.h"
#include "ISubject.h"
// General includes:
#include "CDialogObserver.h"
// Project includes:
#include "LCID.h"


/** Implements IObserver based on the partial implementation CDialogObserver.

	
	@ingroup linescounter
*/
class LCDialogObserver : public CDialogObserver
{
	public:
		/**
			Constructor.
			@param boss interface ptr from boss object on which this interface is aggregated.
		*/
		LCDialogObserver(IPMUnknown* boss) : CDialogObserver(boss) {}

		/** Destructor. */
		virtual ~LCDialogObserver() {}

		/**
			Called by the application to allow the observer to attach to the subjects
			to be observed, in this case the dialog's info button widget. If you want
			to observe other widgets on the dialog you could add them here.
		*/
		virtual void AutoAttach();

		/** Called by the application to allow the observer to detach from the subjects being observed. */
		virtual void AutoDetach();

		/**
			Called by the host when the observed object changes, in this case when
			the dialog's info button is clicked.
			@param theChange specifies the class ID of the change to the subject. Frequently this is a command ID.
			@param theSubject points to the ISubject interface for the subject that has changed.
			@param protocol specifies the ID of the changed interface on the subject boss.
			@param changedBy points to additional data about the change. Often this pointer indicates the class ID of the command that has caused the change.
		*/
		virtual void Update
		(
			const ClassID& theChange,
			ISubject* theSubject,
			const PMIID& protocol,
			void* changedBy
		);
};


/* CREATE_PMINTERFACE
 Binds the C++ implementation class onto its
 ImplementationID making the C++ code callable by the
 application.
*/
CREATE_PMINTERFACE(LCDialogObserver, kLCDialogObserverImpl)

/* AutoAttach
*/
void LCDialogObserver::AutoAttach()
{
	// Call the base class AutoAttach() function so that default behavior
	// will still occur (OK and Cancel buttons, etc.).
	CDialogObserver::AutoAttach();
	do
	{
		InterfacePtr<IPanelControlData> panelControlData(this, UseDefaultIID());
		ASSERT(panelControlData);
		if(!panelControlData) {
			break;
		}
		// Attach to other widgets you want to handle dynamically here.

	} while (kFalse);
}

/* AutoDetach
*/
void LCDialogObserver::AutoDetach()
{
	// Call base class AutoDetach() so that default behavior will occur (OK and Cancel buttons, etc.).
	CDialogObserver::AutoDetach();
	do
	{
		InterfacePtr<IPanelControlData> panelControlData(this, UseDefaultIID());
		ASSERT(panelControlData);
		if(!panelControlData) {
			break;
		}
		// Detach from other widgets you handle dynamically here.

	} while (kFalse);
}

/* Update
*/
void LCDialogObserver::Update
(
	const ClassID& theChange,
	ISubject* theSubject,
	const PMIID& protocol,
	void* changedBy
)
{
	// Call the base class Update function so that default behavior will still occur (OK and Cancel buttons, etc.).
	CDialogObserver::Update(theChange, theSubject, protocol, changedBy);
	do
	{
		InterfacePtr<IControlView> controlView(theSubject, UseDefaultIID());
		ASSERT(controlView);
		if(!controlView) {
			break;
		}
		// Get the button ID from the view.
		WidgetID theSelectedWidget = controlView->GetWidgetID();
		// TODO: process this

	} while (kFalse);
}
