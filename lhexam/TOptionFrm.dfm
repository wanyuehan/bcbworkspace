object OptionFrm: TOptionFrm
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = #35831#36873#25321#24405#20837#30340#21442#25968
  ClientHeight = 170
  ClientWidth = 382
  Color = clBtnFace
  Font.Charset = GB2312_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = True
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 16
  object OKBtn: TButton
    Left = 220
    Top = 24
    Width = 154
    Height = 33
    Caption = #36827#20837#36755#20837
    Default = True
    ModalResult = 1
    TabOrder = 0
    OnClick = OKBtnClick
    OnKeyPress = OKBtnKeyPress
  end
  object CancelBtn: TButton
    Left = 220
    Top = 128
    Width = 154
    Height = 34
    Cancel = True
    Caption = #36864#20986#36755#20837
    ModalResult = 2
    TabOrder = 1
    OnClick = CancelBtnClick
  end
  object rgKM: TRadioGroup
    Left = 24
    Top = 16
    Width = 169
    Height = 55
    Caption = #31185' '#30446
    Columns = 2
    Items.Strings = (
      #29289#29702
      #21270#23398)
    TabOrder = 2
  end
  object rgTurns: TRadioGroup
    Left = 24
    Top = 77
    Width = 169
    Height = 84
    Caption = #36718' '#25968
    Columns = 2
    Items.Strings = (
      #31532#19968#36718
      #31532#20108#36718)
    TabOrder = 3
  end
  object btAdmin: TButton
    Left = 220
    Top = 77
    Width = 154
    Height = 33
    Caption = #36755#20837#26356#27491
    TabOrder = 4
    Visible = False
  end
end
