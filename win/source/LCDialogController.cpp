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
#include "IActiveContext.h"
// General includes:
#include "CDialogController.h"
// Project includes:
#include "LCID.h"
#include <IStoryList.h>
#include <string>
#include <ITextModel.h>
#include <IWaxIterator.h>
#include <IWaxLine.h>
#include <IWaxStrand.h>
#include <CAlert.h>
#include "tinyxml2.h"
#include <chrono>
#include <ctime> 

//using namespace tinyxml2;
// DynamDOM.cpp : Defines the entry point for the console application.
//


/** LCDialogController
	Methods allow for the initialization, validation, and application of dialog widget
	values.
	Implements IDialogController based on the partial implementation CDialogController.

	
	@ingroup linescounter
*/


class LCDialogController : public CDialogController
{
	public:
		/** Constructor.
			@param boss interface ptr from boss object on which this interface is aggregated.
		*/
		LCDialogController(IPMUnknown* boss) : CDialogController(boss) {}

		/** Destructor.
		*/
		virtual ~LCDialogController() {}

		/** Initialize each widget in the dialog with its default value.
			Called when the dialog is opened.
		*/
	       virtual void InitializeDialogFields(IActiveContext* dlgContext);

		/** Validate the values in the widgets.
			By default, the widget with ID kOKButtonWidgetID causes
			ValidateFields to be called. When all widgets are valid,
			ApplyFields will be called.
			@return kDefaultWidgetId if all widget values are valid, WidgetID of the widget to select otherwise.

		*/
	       virtual WidgetID ValidateDialogFields(IActiveContext* myContext);


		/** Retrieve the values from the widgets and act on them.
			@param widgetId identifies the widget on which to act.
		*/
		virtual void ApplyDialogFields(IActiveContext* myContext, const WidgetID& widgetId);
};

CREATE_PMINTERFACE(LCDialogController, kLCDialogControllerImpl)

/* ApplyFields
*/
void LCDialogController::InitializeDialogFields(IActiveContext* dlgContext)
{
	CDialogController::InitializeDialogFields(dlgContext);
	// Put code to initialize widget values here.
}

/* ValidateFields
*/
WidgetID LCDialogController::ValidateDialogFields(IActiveContext* myContext)
{
	WidgetID result = CDialogController::ValidateDialogFields(myContext);
	// Put code to validate widget values here.
	return result;
}

/* ApplyFields
*/
void LCDialogController::ApplyDialogFields(IActiveContext* myContext, const WidgetID& widgetId)
{

	time_t now = time(0);

	char* dt = ctime(&now);

	tinyxml2::XMLDocument xmlDoc;
	tinyxml2::XMLNode* pRoot = xmlDoc.NewElement("root");
	xmlDoc.InsertFirstChild(pRoot);

	tinyxml2::XMLElement* pElementD = xmlDoc.NewElement("Date");
	pElementD->SetText(dt);
	pRoot->InsertEndChild(pElementD);

	tinyxml2::XMLElement* pElementA = xmlDoc.NewElement("Author");
	pElementA->SetText("Alexander Nevgen");
	pRoot->InsertEndChild(pElementA);

	IDocument* doc1 = myContext->GetContextDocument();
	InterfacePtr<IStoryList> storylist((IPMUnknown*)doc1, IID_ISTORYLIST);

	PMString str;
	int32 wcount = 0;
	

	int a;

	for (int32 i = 0; i < storylist->GetUserAccessibleStoryCount(); i++)
	{
		int tmpcount = 0;

		UIDRef storyRef = storylist->GetNthUserAccessibleStoryUID(i);
		if (storyRef == kInvalidUIDRef) {
			continue;
		}

		InterfacePtr<ITextModel> textModel(storyRef, IID_ITEXTMODEL);

		InterfacePtr<IWaxStrand> waxStrand((IWaxStrand*)textModel->QueryStrand(kFrameListBoss, IID_IWAXSTRAND));
		K2::scoped_ptr<IWaxIterator> waxIterator(waxStrand->NewWaxIterator());

		IWaxLine* nextLine;
		IWaxLine* firstLine;

		firstLine = waxIterator->GetFirstWaxLine(0);

		if (firstLine->GetTextSpan() > 1) {
			wcount++;
			tmpcount++;
		}

		while ((nextLine = waxIterator->GetNextWaxLine()) != nil) {

			if (nextLine->GetTextSpan() > 1) {
				wcount++;
				tmpcount++;
			}
		}

		if (textModel->TotalLength() != textModel->GetPrimaryStoryThreadSpan()) {

			wcount--;
			tmpcount--;
			tinyxml2::XMLElement* pElementLC = xmlDoc.NewElement("Table");
			tinyxml2::XMLElement* pElement1LC = xmlDoc.NewElement("ID");
			pElement1LC->SetText(i);
			//pElement1LC->SetText(storyRef.GetUID().Get());
			pElementLC->InsertEndChild(pElement1LC);

			tinyxml2::XMLElement* pElement2LC = xmlDoc.NewElement("LinesCount");
			pElement2LC->SetText(tmpcount);
			pElementLC->InsertEndChild(pElement2LC);

			pRoot->InsertEndChild(pElementLC);
		}
		else {

			tinyxml2::XMLElement* pElement = xmlDoc.NewElement("TextBox");
			tinyxml2::XMLElement* pElement1 = xmlDoc.NewElement("ID");
			pElement1->SetText(i);
			pElement->InsertEndChild(pElement1);

			tinyxml2::XMLElement* pElement2 = xmlDoc.NewElement("LinesCount");
			pElement2->SetText(tmpcount);
			pElement->InsertEndChild(pElement2);
			pRoot->InsertEndChild(pElement);
		}


	}

	tinyxml2::XMLError eResult = xmlDoc.SaveFile("C:/InDesign-Plugin-master/win/XML/MetaData.xml");

	str.Append((WideString)"total lines in document - ");
	str.Append((WideString)std::to_string(wcount).c_str());

	CAlert::InformationAlert(str);
}
