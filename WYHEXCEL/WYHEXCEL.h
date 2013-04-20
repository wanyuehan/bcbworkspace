/****************************************************************************
*          Excel Ole 操作封装类
*          作者   万越寒
*          时间   2010年3月
*          版本   2.1.9
*		   文件名  WYHEXCEL.H
*****************************************************************************/
//---------------------------------------------------------------------------

#ifndef WYHEXCELH
#define WYHEXCELH
#define   PG   OlePropertyGet
#define   PS   OlePropertySet
#define   FN   OleFunction
#define   PR   OleProcedure
#include <comdef.h>
#include <Classes.hpp>
#include <ComObj.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TWYHEXCEL;
class TWYHWORKBOOK;
class TWYHSHEET;
typedef enum _EAlignment{
		AlignLeft=0,
		AlignRight= 4,
		AlignCenter =3,
		AlignRepeat =5,
		AlignWrapped =6,
		AlignFix =8
}EAlignment;
typedef enum _EVAlignment{
		VAlignTop =1,
		VAlignMid =2,
		VAlignBottom =3,
		VAlignFix =4
	}EVAlignment;

typedef enum _EWindowState{

		xlNormal=1,
		xlMinimized=2,
		xlMaximized=3
	}EWindowState;


class TWYHEXCEL{
	private:
		Variant _els;
		TWYHWORKBOOK* _wb;
		char* _filename;
		~TWYHEXCEL();
		TADODataSet * _dataset;
	public:
		TWYHEXCEL(BOOL visible,char* templatefile,TObject* AOwner);
		void SetExcelWindowState(EWindowState stateflag);
		void SetStatuText(char* statutext);
		void SetCaption(char* captiontext);
		void Fill(TADODataSet* dataSet);
        void Fill();
		void Quit();
		Variant InchesToPoints(float num);
		void SetVisible(bool visible);
	__property Variant OLEInstanse={read=_els};
	__property TWYHWORKBOOK* WorkBook={read=_wb,write=_wb};
	__property char* FileName={read=_filename,write=_filename};
	__property TADODataSet* DataSet={read=_dataset,write=_dataset};
};

//------------------------------------------------------------------------------
class TWYHWORKBOOK{
	 private:
		Variant _wb,_filename,_sheets;
		char* _template;

		TWYHEXCEL* app;
		TWYHSHEET* _thissheet;
		~TWYHWORKBOOK();
	 public:
		int SheetCount();
		TWYHWORKBOOK(TWYHEXCEL* application,char* templatefile);
		void Save();
		void SaveTo(char* filename);
		TWYHSHEET* AddSheet();
	    TWYHSHEET* AddSheet(char* tamplatefile);
	 __property Variant Items={read=_wb};
	 __property TWYHEXCEL* Application={read=app};
	 __property char* TemplateFile={read=_template};
	 __property TWYHSHEET* ActiveSheet={read=_thissheet,write=_thissheet};
};
//------------------------------------------------------------------------------
class TWYHSHEET{
	private:
		TWYHEXCEL* _els;
		TWYHWORKBOOK* _wb;
		Variant _sheet;
		char* _tempfile;
		~TWYHSHEET();
	public:
		TWYHSHEET(Variant sheet);
		void Rename(char* newname);
		Variant GetRange(char* rangestr);
		long GetRowsCount();
		int GetColsCount();
		void DisplayPageBreaks(bool isDisplay);
		void SetPageHead(char* left,char* center,char* right);
		void SetPageFoot(char* left,char* center,char* right);
		void SetPrintTitleRow(char* range);
		void SetPrintTiltleColumn(char* range);
		void SetPrintMargin(float left,float right,float top,float bottom,float head,float foot);
		void SetColWidth(int width,char* colNumber);
		void SetRowHeight(int height,char* rowNumber);
		void DeleteRow(char* rowNumber);
		void SetFont(char* rangeStr,char* fontname,long color,int size,bool italic,bool bold,bool underline,char* format);
		void SetBGColor(char* rangeStr,long color);
		void Align(char* rangeStr,int alignflag,int valignflag);
		void AutoWrap(char* rangeStr,bool wrapped);
		void Merge(char* rangeStr);
		void UNMerge(char* rangeStr);
		void AutoGrid(bool autogrid);
		void SetCellsValue(char* rangeStr,char* value);
		void SetCellsValue(long cellx,long celly,char* value);
		void CellReplace(char* what,char* replacement,bool MatchCase);
		Variant GetCellValue(long cellx,long celly);
		void PrintPreview();
		void Print();
	__property TWYHEXCEL* Application={read=_els,write=_els};
	__property TWYHWORKBOOK* WorkBook={read=_wb,write=_wb};
	__property char* TemplateFile={read=_tempfile,write=_tempfile};
};
#endif
//------------------------------------------------------------------------------


