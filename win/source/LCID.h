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


#ifndef __LCID_h__
#define __LCID_h__

#include "SDKDef.h"

// Company:
#define kLCCompanyKey	"Intexsoft"		// Company name used internally for menu paths and the like. Must be globally unique, only A-Z, 0-9, space and "_".
#define kLCCompanyValue	"Intexsoft"	// Company name displayed externally.

// Plug-in:
#define kLCPluginName	"Lines Counter"			// Name of this plug-in.
#define kLCPrefixNumber	0xe9402 		// Unique prefix number for this plug-in(*Must* be obtained from Adobe Developer Support).
#define kLCVersion		kSDKDefPluginVersionString						// Version of this plug-in (for the About Box).
#define kLCAuthor		"Ivan Bakurevich"					// Author of this plug-in (for the About Box).

// Plug-in Prefix: (please change kLCPrefixNumber above to modify the prefix.)
#define kLCPrefix		RezLong(kLCPrefixNumber)				// The unique numeric prefix for all object model IDs for this plug-in.
#define kLCStringPrefix	SDK_DEF_STRINGIZE(kLCPrefixNumber)	// The string equivalent of the unique prefix number for  this plug-in.

// Missing plug-in: (see ExtraPluginInfo resource)
#define kLCMissingPluginURLValue		kSDKDefPartnersStandardValue_enUS // URL displayed in Missing Plug-in dialog
#define kLCMissingPluginAlertValue	kSDKDefMissingPluginAlertValue // Message displayed in Missing Plug-in dialog - provide a string that instructs user how to solve their missing plug-in problem

// PluginID:
DECLARE_PMID(kPlugInIDSpace, kLCPluginID, kLCPrefix + 0)

// ClassIDs:
DECLARE_PMID(kClassIDSpace, kLCActionComponentBoss, kLCPrefix + 0)
DECLARE_PMID(kClassIDSpace, kLCDialogBoss, kLCPrefix + 2)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 3)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 4)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 5)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 6)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 7)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 8)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 9)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 10)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 11)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 12)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 13)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 14)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 15)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 16)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 17)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 18)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 19)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 20)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 21)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 22)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 23)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 24)
//DECLARE_PMID(kClassIDSpace, kLCBoss, kLCPrefix + 25)


// InterfaceIDs:
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 0)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 1)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 2)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 3)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 4)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 5)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 6)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 7)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 8)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 9)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 10)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 11)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 12)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 13)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 14)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 15)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 16)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 17)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 18)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 19)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 20)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 21)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 22)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 23)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 24)
//DECLARE_PMID(kInterfaceIDSpace, IID_ILCINTERFACE, kLCPrefix + 25)


// ImplementationIDs:
DECLARE_PMID(kImplementationIDSpace, kLCActionComponentImpl, kLCPrefix + 0 )
DECLARE_PMID(kImplementationIDSpace, kLCDialogControllerImpl, kLCPrefix + 1 )
DECLARE_PMID(kImplementationIDSpace, kLCDialogObserverImpl, kLCPrefix + 2 )
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 3)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 4)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 5)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 6)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 7)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 8)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 9)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 10)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 11)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 12)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 13)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 14)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 15)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 16)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 17)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 18)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 19)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 20)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 21)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 22)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 23)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 24)
//DECLARE_PMID(kImplementationIDSpace, kLCImpl, kLCPrefix + 25)


// ActionIDs:
DECLARE_PMID(kActionIDSpace, kLCAboutActionID, kLCPrefix + 0)

DECLARE_PMID(kActionIDSpace, kLCDialogActionID, kLCPrefix + 4)
//DECLARE_PMID(kActionIDSpace, kLCActionID, kLCPrefix + 5)
//DECLARE_PMID(kActionIDSpace, kLCActionID, kLCPrefix + 6)
//DECLARE_PMID(kActionIDSpace, kLCActionID, kLCPrefix + 7)
//DECLARE_PMID(kActionIDSpace, kLCActionID, kLCPrefix + 8)
//DECLARE_PMID(kActionIDSpace, kLCActionID, kLCPrefix + 9)
//DECLARE_PMID(kActionIDSpace, kLCActionID, kLCPrefix + 10)
//DECLARE_PMID(kActionIDSpace, kLCActionID, kLCPrefix + 11)
//DECLARE_PMID(kActionIDSpace, kLCActionID, kLCPrefix + 12)
//DECLARE_PMID(kActionIDSpace, kLCActionID, kLCPrefix + 13)
//DECLARE_PMID(kActionIDSpace, kLCActionID, kLCPrefix + 14)
//DECLARE_PMID(kActionIDSpace, kLCActionID, kLCPrefix + 15)
//DECLARE_PMID(kActionIDSpace, kLCActionID, kLCPrefix + 16)
//DECLARE_PMID(kActionIDSpace, kLCActionID, kLCPrefix + 17)
//DECLARE_PMID(kActionIDSpace, kLCActionID, kLCPrefix + 18)
//DECLARE_PMID(kActionIDSpace, kLCActionID, kLCPrefix + 19)
//DECLARE_PMID(kActionIDSpace, kLCActionID, kLCPrefix + 20)
//DECLARE_PMID(kActionIDSpace, kLCActionID, kLCPrefix + 21)
//DECLARE_PMID(kActionIDSpace, kLCActionID, kLCPrefix + 22)
//DECLARE_PMID(kActionIDSpace, kLCActionID, kLCPrefix + 23)
//DECLARE_PMID(kActionIDSpace, kLCActionID, kLCPrefix + 24)
//DECLARE_PMID(kActionIDSpace, kLCActionID, kLCPrefix + 25)


// WidgetIDs:
DECLARE_PMID(kWidgetIDSpace, kLCDialogWidgetID, kLCPrefix + 1)
DECLARE_PMID(kWidgetIDSpace, kLCDropDownListWidgetID, kLCPrefix + 2)
DECLARE_PMID(kWidgetIDSpace, kLCTextEditBoxWidgetID, kLCPrefix + 3)
DECLARE_PMID(kWidgetIDSpace, kLCStaticTextWidgetID, kLCPrefix + 4)
//DECLARE_PMID(kWidgetIDSpace, kLCWidgetID, kLCPrefix + 5)
//DECLARE_PMID(kWidgetIDSpace, kLCWidgetID, kLCPrefix + 6)
//DECLARE_PMID(kWidgetIDSpace, kLCWidgetID, kLCPrefix + 7)
//DECLARE_PMID(kWidgetIDSpace, kLCWidgetID, kLCPrefix + 8)
//DECLARE_PMID(kWidgetIDSpace, kLCWidgetID, kLCPrefix + 9)
//DECLARE_PMID(kWidgetIDSpace, kLCWidgetID, kLCPrefix + 10)
//DECLARE_PMID(kWidgetIDSpace, kLCWidgetID, kLCPrefix + 11)
//DECLARE_PMID(kWidgetIDSpace, kLCWidgetID, kLCPrefix + 12)
//DECLARE_PMID(kWidgetIDSpace, kLCWidgetID, kLCPrefix + 13)
//DECLARE_PMID(kWidgetIDSpace, kLCWidgetID, kLCPrefix + 14)
//DECLARE_PMID(kWidgetIDSpace, kLCWidgetID, kLCPrefix + 15)
//DECLARE_PMID(kWidgetIDSpace, kLCWidgetID, kLCPrefix + 16)
//DECLARE_PMID(kWidgetIDSpace, kLCWidgetID, kLCPrefix + 17)
//DECLARE_PMID(kWidgetIDSpace, kLCWidgetID, kLCPrefix + 18)
//DECLARE_PMID(kWidgetIDSpace, kLCWidgetID, kLCPrefix + 19)
//DECLARE_PMID(kWidgetIDSpace, kLCWidgetID, kLCPrefix + 20)
//DECLARE_PMID(kWidgetIDSpace, kLCWidgetID, kLCPrefix + 21)
//DECLARE_PMID(kWidgetIDSpace, kLCWidgetID, kLCPrefix + 22)
//DECLARE_PMID(kWidgetIDSpace, kLCWidgetID, kLCPrefix + 23)
//DECLARE_PMID(kWidgetIDSpace, kLCWidgetID, kLCPrefix + 24)
//DECLARE_PMID(kWidgetIDSpace, kLCWidgetID, kLCPrefix + 25)


// "About Plug-ins" sub-menu:
#define kLCAboutMenuKey			kLCStringPrefix "kLCAboutMenuKey"
#define kLCAboutMenuPath		kSDKDefStandardAboutMenuPath kLCCompanyKey

// "Plug-ins" sub-menu:
#define kLCPluginsMenuKey 		kLCStringPrefix "LC"
#define kLCPluginsMenuPath		kSDKDefPlugInsStandardMenuPath kLCCompanyKey kSDKDefDelimitMenuPath kLCPluginsMenuKey

// Menu item keys:

// Other StringKeys:
#define kLCAboutBoxStringKey	kLCStringPrefix "kLCAboutBoxStringKey"
#define kLCTargetMenuPath kLCPluginsMenuPath

#define kLCDropDownItem_1Key "Item 1"
#define kLCDropDownItem_2Key "Item 2"
#define kLCDropDownItem_3Key "Item 3"

#define kLCStaticTextKey kLCStringPrefix "kLCStaticTextKey"

// Menu item positions:

#define kLCDialogTitleKey kLCStringPrefix " Lines Counter Plugin"
// "Plug-ins" sub-menu item key for dialog:
#define kLCDialogMenuItemKey "Lines Counter"
// "Plug-ins" sub-menu item position for dialog:
#define kLCDialogMenuItemPosition	12.0


// Initial data format version numbers
#define kLCFirstMajorFormatNumber  RezLong(1)
#define kLCFirstMinorFormatNumber  RezLong(0)

// Data format version numbers for the PluginVersion resource 
#define kLCCurrentMajorFormatNumber kLCFirstMajorFormatNumber
#define kLCCurrentMinorFormatNumber kLCFirstMinorFormatNumber

#endif // __LCID_h__
