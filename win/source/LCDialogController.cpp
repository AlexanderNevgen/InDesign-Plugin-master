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
#include "ISelectionManager.h"
#include "ITextEditSuite.h"
#include <IStoryList.h>
#include <IComposeScanner.h>
#include <string>
#include <IDataStringUtils.h>
#include <ITextModel.h>
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
	PMString resultString;
	resultString = this->GetTextControlData(kLCDropDownListWidgetID);
	resultString.Translate();

	PMString editBoxString = this->GetTextControlData(kLCTextEditBoxWidgetID);
	PMString moneySign(kLCStaticTextKey);
	moneySign.Translate();

	resultString.Append('\t');
	resultString.Append(moneySign);
	resultString.Append(editBoxString);
	
	InterfacePtr<ITextEditSuite> textEditSuite(myContext->GetContextSelection(), UseDefaultIID());

	IDocument* doc1 = myContext->GetContextDocument();

	InterfacePtr<IStoryList> storylist((IPMUnknown*)doc1, IID_ISTORYLIST);

	PMString str;
	int finalCounter = 0;

	for (int32 i = 0; i < storylist->GetUserAccessibleStoryCount(); i++) {

		UIDRef storyRef = storylist->GetNthUserAccessibleStoryUID(i);
		if (storyRef == kInvalidUIDRef) {
			continue;
		}

		InterfacePtr<ITextModel> textModel(storyRef, IID_ITEXTMODEL);

		InterfacePtr<IComposeScanner> scanner(storylist->GetNthUserAccessibleStoryUID(i), UseDefaultIID());

		WideString wstr;
		scanner->CopyText(0, textModel->TotalLength(), &wstr);
		
		uint32 CARRIAGE_RETURN_HEX = 0x0D;
		int index = 0;

		if(textModel->TotalLength() != textModel->GetPrimaryStoryThreadSpan()) {
			index = textModel->GetPrimaryStoryThreadSpan();
		}

		int counter = 0;
		for (int i = index; i < wstr.Length(); i++) {
			if (wstr.GetChar(i) != UTF32TextChar(CARRIAGE_RETURN_HEX)) {
				counter++;
			}
			else {
				if (counter != 0) {
					finalCounter++;
				}
				counter = 0;
			}
		}
		
	}

	str.Append((WideString)std::to_string(finalCounter).c_str());

	if (textEditSuite && textEditSuite->CanEditText()) {
		ErrorCode status = textEditSuite->InsertText(WideString(str));
		ASSERT_MSG(status == kSuccess, "LCDialogController::ApplyFields: can't insert text");
	}

}
