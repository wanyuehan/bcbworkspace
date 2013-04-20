object SvrForm: TSvrForm
  Left = 168
  Top = 154
  Caption = #39532#38797#23665#24066'2013'#24180#21021#20013#20307#32946#20250#32771#25104#32489#24405#20837#31243#24207' '#26381#21153#22120#31471
  ClientHeight = 441
  ClientWidth = 783
  Color = clBtnFace
  Font.Charset = GB2312_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 11
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 783
    Height = 169
    Align = alTop
    Caption = ' '#24405#20837#36827#24230#30417#35270' '
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    DesignSize = (
      783
      169)
    object F1LB: TLabel
      Left = 18
      Top = 22
      Width = 84
      Height = 12
      Caption = #31532#19968#36718#36755#20837#36827#24230
    end
    object T2LB: TLabel
      Left = 18
      Top = 86
      Width = 84
      Height = 12
      Caption = #31532#20108#36718#36755#20837#36827#24230
    end
    object Label1: TLabel
      Left = 16
      Top = 142
      Width = 48
      Height = 12
      Caption = #21047#26032#39057#29575
    end
    object Label2: TLabel
      Left = 123
      Top = 23
      Width = 36
      Height = 12
      Caption = 'Label2'
    end
    object Label3: TLabel
      Left = 123
      Top = 87
      Width = 36
      Height = 12
      Caption = 'Label2'
    end
    object T1PB: TProgressBar
      Left = 16
      Top = 45
      Width = 753
      Height = 25
      Anchors = [akLeft, akRight]
      Smooth = True
      TabOrder = 0
    end
    object T2PB: TProgressBar
      Left = 16
      Top = 106
      Width = 753
      Height = 25
      Anchors = [akLeft, akRight]
      Smooth = True
      TabOrder = 1
    end
    object TrackBar1: TTrackBar
      Left = 63
      Top = 136
      Width = 150
      Height = 45
      Min = 1
      Position = 1
      TabOrder = 2
      OnChange = TrackBar1Change
    end
    object bt_PDSet: TButton
      Left = 679
      Top = 20
      Width = 90
      Height = 19
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #25104#32489#21028#23450#35774#32622
      TabOrder = 3
      OnClick = bt_PDSetClick
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 169
    Width = 783
    Height = 272
    Align = alClient
    BevelOuter = bvLowered
    TabOrder = 1
    object GroupBox2: TGroupBox
      Left = 1
      Top = 1
      Width = 272
      Height = 270
      Align = alLeft
      Caption = #21151#33021#38754#26495
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      object Memo1: TMemo
        Left = 8
        Top = 16
        Width = 257
        Height = 89
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        ScrollBars = ssVertical
        TabOrder = 0
      end
      object btnExcSql: TButton
        Left = 8
        Top = 112
        Width = 257
        Height = 33
        Caption = #25191#34892#26597#35810
        TabOrder = 1
        OnClick = btnExcSqlClick
      end
      object btnClrScore: TButton
        Left = 8
        Top = 160
        Width = 121
        Height = 41
        Caption = #28165#38500#26576#32452#25104#32489
        TabOrder = 2
        OnClick = btnClrScoreClick
      end
      object btnChkInput: TButton
        Left = 136
        Top = 160
        Width = 129
        Height = 41
        Caption = #25191#34892#21452#24037#26657#39564
        TabOrder = 3
        OnClick = btnChkInputClick
      end
      object btnPrint: TButton
        Left = 7
        Top = 216
        Width = 122
        Height = 41
        Caption = #20998#25253#21517#28857#25171#21360
        TabOrder = 4
        OnClick = btnPrintClick
      end
      object btnParseScore: TButton
        Left = 136
        Top = 216
        Width = 129
        Height = 41
        Caption = #25104#32489#21028#23450
        TabOrder = 5
        OnClick = btnParseScoreClick
      end
    end
    object DBGrid1: TDBGrid
      Left = 273
      Top = 1
      Width = 509
      Height = 270
      Align = alClient
      DataSource = DS
      ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      ReadOnly = True
      TabOrder = 1
      TitleFont.Charset = GB2312_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = []
    end
  end
  object RS: TADOQuery
    Connection = MAINCONN
    Parameters = <>
    Left = 656
    Top = 416
  end
  object CMD: TADOCommand
    Connection = MAINCONN
    Parameters = <>
    Left = 624
    Top = 416
  end
  object DS: TDataSource
    AutoEdit = False
    DataSet = RS
    Left = 720
    Top = 416
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 592
    Top = 416
  end
  object RS1: TADOQuery
    Connection = MAINCONN
    Parameters = <>
    Left = 560
    Top = 416
  end
  object SCORERS: TADOQuery
    Connection = MAINCONN
    CursorType = ctStatic
    DataSource = DS
    Parameters = <>
    SQL.Strings = (
      'select * from cjpd')
    Left = 752
    Top = 416
  end
  object MAINCONN: TADOConnection
    LoginPrompt = False
    Provider = 'SQLOLEDB'
    Left = 688
    Top = 416
  end
end
