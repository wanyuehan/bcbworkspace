object frmEdit: TfrmEdit
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #26356#27491#31383#21475
  ClientHeight = 122
  ClientWidth = 580
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 40
    Width = 108
    Height = 33
    Caption = #26356#27491#25104#32489
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object btSave: TButton
    Left = 488
    Top = 32
    Width = 67
    Height = 49
    Caption = #20445#23384
    TabOrder = 0
    OnClick = btSaveClick
  end
  object meScore: TMaskEdit
    Left = 130
    Top = 31
    Width = 140
    Height = 48
    Alignment = taCenter
    BorderStyle = bsNone
    Color = clSilver
    DoubleBuffered = False
    EditMask = '!9.99;1;_'
    Font.Charset = GB2312_CHARSET
    Font.Color = clRed
    Font.Height = -33
    Font.Name = 'Tahoma'
    Font.Style = []
    MaxLength = 4
    ParentDoubleBuffered = False
    ParentFont = False
    TabOrder = 1
    Text = ' .  '
  end
  object cbSubject: TComboBox
    Left = 288
    Top = 46
    Width = 145
    Height = 21
    Style = csDropDownList
    TabOrder = 2
    Items.Strings = (
      #29289#29702
      #21270#23398)
  end
end
