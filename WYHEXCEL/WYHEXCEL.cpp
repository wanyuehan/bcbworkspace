//---------------------------------------------------------------------------
#pragma hdrstop
#include "WYHEXCEL.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
TWYHEXCEL::TWYHEXCEL(BOOL visible,char* templatefile,TObject* AOwner)
{
	_els=NULL;
	try
	{
		_els=CreateOleObject("Excel.Application"); //启动Excel
	}catch(...){
		MessageBox(NULL,"启动Excel失败，请检查是否安装了EXCEL2003以上版本。","发生错误！",MB_OK|MB_ICONWARNING);

	}
	try
	{
		_els.PS("Visible",(Variant)visible);
		_wb=new TWYHWORKBOOK(this,templatefile);
	}catch(...){}
}
//------------------------------------------------------------------------------
	TWYHEXCEL::~TWYHEXCEL()
{
	try
	{
		if(!_els){_els.PR("Quit");}
	}catch(...){}
}

//------------------------------------------------------------------------------
void TWYHEXCEL::Quit(){
	try {
		_els.PR("Quit");
	}catch(...){
		return;
	}
}
//------------------------------------------------------------------------------
Variant TWYHEXCEL::InchesToPoints(float num){
     try {
	   return _els.FN("InchesToPoints",num);
	}catch(...){
		return 1;
	}
}
//------------------------------------------------------------------------------
void TWYHEXCEL::SetExcelWindowState(EWindowState stateflag){
	try {
		_els.PS("Windowstate",stateflag);
	}catch(...){
		return;
	}
}
//------------------------------------------------------------------------------
void TWYHEXCEL::SetStatuText(char* statutext){
	try {
		_els.PS("StatusBar",statutext);
	}catch(...){
		return;
	}
}
//------------------------------------------------------------------------------
void TWYHEXCEL::SetCaption(char* captiontext){
	try {
		_els.PS("Caption",captiontext);
	}catch(...){
		return;
	}
}
//------------------------------------------------------------------------------
void TWYHEXCEL::Fill(TADODataSet* dataSet){
	_dataset=dataSet;
	Fill();
}
//------------------------------------------------------------------------------
void TWYHEXCEL::Fill(){
    if (_dataset==NULL||_dataset->Active==false) {
		   return;
	}
	try {
			_wb->AddSheet();
		  for(long j=-1;j<_dataset->RecordCount;j++)
		  for(int i=0;i<_dataset->FieldDefs->Count;i++){
			if(j==-1)_wb->ActiveSheet->SetCellsValue(1,i+1,AnsiString(_dataset->FieldDefs->Items[i]->Name).c_str() );
			else{
				 _wb->ActiveSheet->SetCellsValue(j+2,i+1,_dataset->Fields->Fields[i]->AsAnsiString.c_str());
                 _dataset->Next();
			}
		  }


	}catch(...){
		return;
	}
}
//-------------------------------WORKBOOK---------------------------------------
 TWYHWORKBOOK::TWYHWORKBOOK(TWYHEXCEL* application,char* templatefile){
		 try{
			 _wb=application->OLEInstanse.PG("WorkBooks");
			 app=application;
			 if(templatefile!=NULL)_thissheet=new TWYHSHEET(_wb.FN("Add",WideString(templatefile).c_bstr()));
			 else{
				 _thissheet=new TWYHSHEET(_wb.FN("Add"));
			 }
			 _template=templatefile;
			 }catch(...){
			MessageBox(NULL,"创建工作簿失败！","发生错误！",MB_OK|MB_ICONWARNING);
			_wb=NULL;
		 }
  }
//-------------------------------~WORKBOOK---------------------------------------
 TWYHWORKBOOK::~TWYHWORKBOOK(){
		 try{

			 _wb.PR("Close");
			 _wb=NULL;
		 }catch(...){

		 }
  }

//------------------------------------------------------------------------------
   void TWYHWORKBOOK::Save(){
	try {
		_wb.FN("Save");
	}catch(...){
		MessageBox(NULL,"保存文件失败！","发生错误！",MB_OK|MB_ICONWARNING);
	}
   }
//------------------------------------------------------------------------------
void TWYHWORKBOOK::SaveTo(char* filename){
	try {
		_wb.FN("SaveTo",filename);
	}catch(...){
		MessageBox(NULL,"保存文件失败！","发生错误！",MB_OK|MB_ICONWARNING);
		return;
	}
}
//------------------------------------------------------------------------------
TWYHSHEET* TWYHWORKBOOK::AddSheet(){
	try {
		_sheets=app->OLEInstanse.PG("Sheets");
		_thissheet=new TWYHSHEET(_sheets.FN("Add"));
		_thissheet->WorkBook=this;
		_thissheet->Application=this->app;
	}catch(...){
		MessageBox(NULL,"添加工作表失败！","发生错误！",MB_OK|MB_ICONWARNING);
	}
	return _thissheet;
}
//------------------------------------------------------------------------------
TWYHSHEET* TWYHWORKBOOK::AddSheet(char* templatefile){
	try {
		_sheets=app->OLEInstanse.PG("Sheets");
		Variant vt;
		vt.vt = VT_ERROR;
		V_ERROR(&vt) = DISP_E_PARAMNOTFOUND;
		_thissheet=new TWYHSHEET(_sheets.FN("Add",vt,vt,vt,WideString(templatefile).c_bstr()));
		_template=templatefile;
		_thissheet->WorkBook=this;
		_thissheet->Application=this->app;

	}catch(...){
		MessageBox(NULL,"添加工作表失败！","发生错误！",MB_OK|MB_ICONWARNING);
	}
	return _thissheet;

}
//------------------------------------------------------------------------------
TWYHSHEET::TWYHSHEET(Variant sheet){
	_sheet=sheet;
}
//------------------------------------------------------------------------------
TWYHSHEET::~TWYHSHEET(){
	try {
		_sheet.PR("Delete");
		_sheet=NULL;
	}catch(...){}
}
//------------------------------------------------------------------------------
void TWYHSHEET::Rename(char* newname){
	try {
	 	_sheet.PS("Name",newname);
	}catch(...){}
}
//------------------------------------------------------------------------------
long TWYHSHEET::GetRowsCount(){
	  //
	  return 0;
}
//------------------------------------------------------------------------------
int TWYHSHEET::GetColsCount(){
	 //
	 return 0;
}
//------------------------------------------------------------------------------
void TWYHSHEET::SetPageHead(char* left,char* center,char* right){
		try {
				  _sheet.PG("PageSetup").PS("LeftHeader",left);
				  _sheet.PG("PageSetup").PS("CenterHeader",center);
				  _sheet.PG("PageSetup").PS("RightHeader",right);
		}catch(...){}
}
//------------------------------------------------------------------------------
void TWYHSHEET::SetPageFoot(char* left,char* center,char* right){
		try {
				  _sheet.PG("PageSetup").PS("LeftFooter",left);
				  _sheet.PG("PageSetup").PS("CenterFooter",center);
				  _sheet.PG("PageSetup").PS("RightFooter",right);
		}catch(...){}
}
//------------------------------------------------------------------------------
void TWYHSHEET::SetPrintTitleRow(char* range){
		  try {
			_sheet.PG("PageSetup").PS("PrintTitleRows",range);
		  }catch(...){}
}
//------------------------------------------------------------------------------
void TWYHSHEET::SetPrintTiltleColumn(char* range){
		 try {
			_sheet.PG("PageSetup").PS("PrintTitleColumns",range);
		 }catch(...){}
}
//------------------------------------------------------------------------------
Variant TWYHSHEET::GetRange(char* rangestr){
	   try {
		 return 	_sheet.PG("Range",rangestr);}
	   catch(...){return Null;}
}
//------------------------------------------------------------------------------
void TWYHSHEET::SetPrintMargin(float left,float right,float top,float bottom,float head,float foot){
      try {
			_sheet.PG("PageSetup").PS("LeftMargin",_els->InchesToPoints(left));
			_sheet.PG("PageSetup").PS("RightMargin",_els->InchesToPoints(right));
			_sheet.PG("PageSetup").PS("TopMargin",_els->InchesToPoints(top));
			_sheet.PG("PageSetup").PS("BottomMargin",_els->InchesToPoints(bottom));
			_sheet.PG("PageSetup").PS("HeaderMargin",_els->InchesToPoints(head));
			_sheet.PG("PageSetup").PS("FooterMargin",_els->InchesToPoints(foot));
		 }catch(...){}
}
//------------------------------------------------------------------------------
void TWYHSHEET::SetColWidth(int width,char* colNumber){
	  try {
		_els->OLEInstanse.PG("Columns", colNumber).PS("ColumnWidth", width);
	  }catch(...){}
}
//------------------------------------------------------------------------------
void TWYHSHEET::SetRowHeight(int width,char* rowNumber){
	  try {
		_els->OLEInstanse.PG("Rows", rowNumber).PS("RowHeight", width);
	  }catch(...){}
}
//------------------------------------------------------------------------------
void TWYHSHEET::DeleteRow(char* rowNumber){
	  try {
		Variant range=GetRange(rowNumber);
		range.PR("Delete");
	  }catch(...){}
}
//------------------------------------------------------------------------------
void TWYHSHEET::DisplayPageBreaks(bool isDisplay){
	 try {
		_sheet.PS("DisplayPageBreaks",isDisplay);
	  }catch(...){}
}
//------------------------------------------------------------------------------
void TWYHSHEET::AutoGrid(bool autogrid){
	 try {
		_sheet.PG("PageSetup").PS("PrintGridlines",autogrid);
	  }catch(...){}
}
//------------------------------------------------------------------------------
void TWYHSHEET::SetFont(char* rangeStr,char* fontname,long color,int size,bool italic,bool bold,bool underline,char* format){
	 try {
		Variant range=GetRange(rangeStr);
		if(fontname!=NULL)range.PG("Font").PS("Name",fontname);
		if(color!=-1)range.PG("Font").PS("Color",color);
		if(size!=-1)range.PG("Font").PS("Size",size);
		range.PG("Font").PS("Italic",italic);
		range.PG("Font").PS("Bold",bold);
		if(underline)
			range.PG("Font").PS("Underline",2);
		else{
			range.PG("Font").PS("Underline",1);
		}
		if(format!=NULL)range.PS("NumberFormatLocal",format);

	  }catch(...){}
}
//------------------------------------------------------------------------------
void TWYHSHEET::SetBGColor(char* rangeStr,long color){
	try {
		Variant range=GetRange(rangeStr);
		range.PG("Interior").PS("Color",color);
		range.PG("Interior").PS("Pattern",1);
	}catch(...){}
}
//------------------------------------------------------------------------------
void TWYHSHEET::Align(char* rangeStr,int alignflag,int valignflag){
	try {
		Variant range=GetRange(rangeStr);
		range.PS("HorizontalAlignment",alignflag);
		range.PS("VerticalAlignment",valignflag);
	}catch(...){}
}
//------------------------------------------------------------------------------
void TWYHSHEET::AutoWrap(char* rangeStr,bool wrapped){
	try {
		Variant range=GetRange(rangeStr);
		range.PS("WrapText",wrapped);
	}catch(...){}
}
//------------------------------------------------------------------------------
void TWYHSHEET::Merge(char* rangeStr){
	try {
		Variant range=GetRange(rangeStr);
		range.PR("Merge");
	}catch(...){}
}
//------------------------------------------------------------------------------
void TWYHSHEET::UNMerge(char* rangeStr){
	try {
		Variant range=GetRange(rangeStr);
		range.PR("UnMerge");
	}catch(...){}
}
//------------------------------------------------------------------------------
void TWYHSHEET::SetCellsValue(char* rangeStr,char* value){
	try {
		Variant range=GetRange(rangeStr);
		range.PG("Cells").PS("Value",WideString(value).c_bstr());
	}catch(...){}
}
//------------------------------------------------------------------------------
void TWYHSHEET::SetCellsValue(long cellx,long celly,char* value){
   try {
		_sheet.PG("Cells",cellx,celly).PS("Value",WideString(value).c_bstr());
	}catch(...){}
}
//------------------------------------------------------------------------------
void TWYHSHEET::CellReplace(char* what,char* replacement,bool MatchCase){
   try {
		_sheet.PG("Cells").FN("Replace",WideString(what).c_bstr(),WideString(replacement).c_bstr(),2,1,MatchCase,false,false);
	}catch(...){}
}
//------------------------------------------------------------------------------
Variant TWYHSHEET::GetCellValue(long cellx,long celly){
	try {
		return _sheet.PG("Cells",cellx,celly).PG("Value");
	}catch(...){return Null;}
}
//------------------------------------------------------------------------------
void TWYHSHEET::PrintPreview(){
	try {

		return _sheet.PR("PrintPreview");
	}catch(...){}
}
//------------------------------------------------------------------------------
void TWYHSHEET::Print(){
	try {
		return _sheet.PR("PrintOut");
	}catch(...){}
}

