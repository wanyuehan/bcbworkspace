object pdFrm: TpdFrm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #25104#32489#21028#23450#35774#32622
  ClientHeight = 320
  ClientWidth = 550
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 12
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 550
    Height = 43
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Align = alTop
    Caption = #35774#23450
    TabOrder = 0
    object Label1: TLabel
      Left = 12
      Top = 18
      Width = 30
      Height = 12
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #24615#21035#65306
    end
    object Label2: TLabel
      Left = 143
      Top = 18
      Width = 30
      Height = 12
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #31185#30446#65306
    end
    object isMale: TRadioButton
      Left = 50
      Top = 19
      Width = 41
      Height = 13
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #30007#23376
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object isFemal: TRadioButton
      Left = 95
      Top = 19
      Width = 44
      Height = 13
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #22899#23376
      TabOrder = 1
    end
    object cbSubjects: TComboBox
      Left = 182
      Top = 16
      Width = 108
      Height = 20
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Style = csDropDownList
      TabOrder = 2
    end
    object Button1: TButton
      Left = 295
      Top = 13
      Width = 75
      Height = 25
      Caption = #21047#26032
      TabOrder = 3
      OnClick = Button1Click
    end
  end
  object DBNavigator1: TDBNavigator
    Left = 0
    Top = 301
    Width = 550
    Height = 19
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    DataSource = DS
    Align = alBottom
    TabOrder = 1
  end
  object DBGrid1: TDBGrid
    Left = 0
    Top = 43
    Width = 550
    Height = 258
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Align = alClient
    DataSource = DS
    TabOrder = 2
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -10
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object DS: TDataSource
    DataSet = RS
    Left = 448
    Top = 16
  end
  object RS: TADOTable
    CursorType = ctStatic
    TableDirect = True
    TableName = 'cjpd'
    Left = 488
    Top = 16
    object RSkslb: TSmallintField
      DisplayWidth = 13
      FieldName = 'kslb'
    end
    object RScj: TFloatField
      DisplayWidth = 22
      FieldName = 'cj'
    end
    object RSscore: TFloatField
      DisplayWidth = 13
      FieldName = 'score'
    end
    object RSsex: TSmallintField
      DisplayWidth = 13
      FieldName = 'sex'
    end
  end
end
