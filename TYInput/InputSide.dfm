object Form1: TForm1
  Left = 205
  Top = 120
  Caption = '2013'#24180#21021#20013#21319#23398#20307#32946#32771#35797#25104#32489#32479#35745#31995#32479#24405#20837#31471
  ClientHeight = 504
  ClientWidth = 731
  Color = clBtnFace
  Font.Charset = GB2312_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object INFOPANEL: TPanel
    Left = 0
    Top = 0
    Width = 731
    Height = 41
    Align = alTop
    BevelInner = bvLowered
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 0
    Top = 41
    Width = 731
    Height = 56
    Align = alTop
    TabOrder = 1
    object GroupBox1: TGroupBox
      Left = 1
      Top = 1
      Width = 729
      Height = 54
      Align = alClient
      Caption = #24405#20837#35774#23450
      TabOrder = 0
      DesignSize = (
        729
        54)
      object Label1: TLabel
        Left = 16
        Top = 24
        Width = 46
        Height = 13
        Caption = #25253#21517#28857':'
      end
      object Label2: TLabel
        Left = 295
        Top = 24
        Width = 59
        Height = 13
        Anchors = [akTop, akRight, akBottom]
        Caption = #36873#32771#32452#21512':'
      end
      object Label3: TLabel
        Left = 471
        Top = 24
        Width = 33
        Height = 13
        Anchors = [akTop, akRight, akBottom]
        Caption = #32452#21035':'
      end
      object Label4: TLabel
        Left = 575
        Top = 24
        Width = 13
        Height = 13
        Anchors = [akTop, akRight, akBottom]
        Caption = #31532
      end
      object Label5: TLabel
        Left = 623
        Top = 24
        Width = 13
        Height = 13
        Anchors = [akTop, akRight, akBottom]
        Caption = #32452
      end
      object BMDLIST: TComboBox
        Left = 64
        Top = 20
        Width = 217
        Height = 22
        Style = csOwnerDrawFixed
        ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        Sorted = True
        TabOrder = 0
      end
      object SEXCB: TComboBox
        Left = 508
        Top = 20
        Width = 60
        Height = 21
        Style = csDropDownList
        Anchors = [akTop, akRight, akBottom]
        ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        ItemIndex = 0
        TabOrder = 2
        Text = #30007#23376
        Items.Strings = (
          #30007#23376
          #22899#23376)
      end
      object GROUPID: TMaskEdit
        Left = 591
        Top = 21
        Width = 29
        Height = 21
        Anchors = [akTop, akRight, akBottom]
        EditMask = '99;1;_'
        ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        MaxLength = 2
        TabOrder = 3
        Text = '  '
        OnKeyDown = GROUPIDKeyDown
        OnKeyPress = GROUPIDKeyPress
      end
      object FILTER: TButton
        Left = 639
        Top = 16
        Width = 75
        Height = 28
        Anchors = [akTop, akRight, akBottom]
        Caption = #30830#23450
        TabOrder = 4
        OnClick = FILTERClick
      end
      object XKLB: TComboBox
        Left = 361
        Top = 20
        Width = 104
        Height = 21
        Style = csDropDownList
        ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        TabOrder = 1
        Items.Strings = (
          '')
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 97
    Width = 177
    Height = 407
    Align = alLeft
    BevelInner = bvLowered
    BevelOuter = bvSpace
    TabOrder = 2
    object Label6: TLabel
      Left = 16
      Top = 16
      Width = 39
      Height = 13
      Caption = #36873#32771#31185
    end
    object Label7: TLabel
      Left = 16
      Top = 48
      Width = 40
      Height = 13
      Caption = #25490'  '#29699
    end
    object Label8: TLabel
      Left = 16
      Top = 80
      Width = 40
      Height = 13
      Caption = #38271'  '#36305
    end
    object tx_cj1: TMaskEdit
      Left = 72
      Top = 11
      Width = 37
      Height = 21
      BorderStyle = bsNone
      EditMask = '000;1;_'
      ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      MaxLength = 3
      TabOrder = 0
      Text = '   '
      OnKeyDown = tx_cj1KeyDown
      OnKeyPress = tx_cj1KeyPress
    end
    object tx_cj2: TMaskEdit
      Left = 72
      Top = 43
      Width = 35
      Height = 21
      BorderStyle = bsNone
      EditMask = '99;1;_'
      ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      MaxLength = 2
      TabOrder = 1
      Text = '  '
      OnKeyDown = tx_cj2KeyDown
      OnKeyPress = tx_cj2KeyPress
    end
    object tx_xkcj: TMaskEdit
      Left = 72
      Top = 75
      Width = 41
      Height = 21
      BorderStyle = bsNone
      EditMask = '9.99;1;_'
      ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      MaxLength = 4
      TabOrder = 2
      Text = ' .  '
      OnKeyDown = tx_xkcjKeyDown
      OnKeyPress = tx_xkcjKeyPress
    end
    object CancelBT: TButton
      Left = 16
      Top = 208
      Width = 137
      Height = 57
      Caption = #21462#28040#26412#36718#36755#20837
      Enabled = False
      TabOrder = 4
      OnClick = CancelBTClick
    end
    object SAVEBT: TButton
      Left = 16
      Top = 136
      Width = 137
      Height = 57
      Caption = #20445#23384#26412#36718#36755#20837
      Enabled = False
      TabOrder = 3
      OnClick = SAVEBTClick
    end
    object Button1: TButton
      Left = 16
      Top = 280
      Width = 137
      Height = 57
      Caption = #37325#26032#36873#21462
      TabOrder = 5
      OnClick = Button1Click
    end
  end
  object GroupBox2: TGroupBox
    Left = 177
    Top = 97
    Width = 554
    Height = 407
    Align = alClient
    Caption = #26412#32452#23398#29983#25968#37327
    TabOrder = 3
    object DG: TDBGrid
      Left = 2
      Top = 15
      Width = 550
      Height = 390
      Align = alClient
      DataSource = DS
      ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgAlwaysShowSelection, dgCancelOnExit]
      TabOrder = 0
      TitleFont.Charset = GB2312_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -13
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = []
      OnCellClick = DGCellClick
      Columns = <
        item
          Expanded = False
          FieldName = 'FZKH'
          Title.Caption = #20934#32771#21495
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'FXM'
          Title.Caption = #22995#21517
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'FTYJSH'
          Title.Caption = #20307#32946#21152#35797#21495
          Width = 82
          Visible = True
        end
        item
          Expanded = False
          Visible = True
        end
        item
          Expanded = False
          Visible = True
        end
        item
          Expanded = False
          Visible = True
        end>
    end
  end
  object CONN: TADOConnection
    ConnectionString = 'FILE NAME=CONN.UDL'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 400
    Top = 448
  end
  object RS1: TADOTable
    Connection = CONN
    CursorType = ctStatic
    LockType = ltBatchOptimistic
    AfterEdit = RS1AfterEdit
    IndexFieldNames = 'ftyjsh'
    TableName = 'resault'
    Left = 432
    Top = 448
    object RS1FZKH: TWideStringField
      FieldName = 'FZKH'
      Size = 12
    end
    object RS1FXM: TWideStringField
      FieldName = 'FXM'
      Size = 8
    end
    object RS1FZWH: TWideStringField
      FieldName = 'FZWH'
      Size = 10
    end
    object RS1FBMDMC: TWideStringField
      FieldName = 'FBMDMC'
      Size = 40
    end
    object RS1FTYJSH: TWideStringField
      FieldName = 'FTYJSH'
      Size = 14
    end
    object RS1SEX: TWideStringField
      FieldName = 'SEX'
      Size = 255
    end
    object RS1kslb: TWideStringField
      FieldName = 'kslb'
      Size = 255
    end
    object RS1groupid: TWideStringField
      FieldName = 'groupid'
      Size = 255
    end
    object RS1xh: TWideStringField
      FieldName = 'xh'
      Size = 255
    end
    object RS1bmddm: TWideStringField
      FieldName = 'fbmddm'
      Size = 255
    end
    object RS1XK_CJ1: TFloatField
      FieldName = 'XK_CJ1'
      DisplayFormat = '0.00'
    end
    object RS1XK_CJ2: TFloatField
      FieldName = 'XK_CJ2'
      DisplayFormat = '0.00'
    end
    object RS1XK_CJ: TFloatField
      FieldName = 'XK_CJ'
      DisplayFormat = '0.00'
    end
    object RS1XKFS: TFloatField
      FieldName = 'XKFS'
      DisplayFormat = '0.0'
    end
    object RS1CJ11: TFloatField
      FieldName = 'CJ11'
      DisplayFormat = '0.00'
    end
    object RS1CJ12: TFloatField
      FieldName = 'CJ12'
      DisplayFormat = '0.00'
    end
    object RS1CJ1: TFloatField
      FieldName = 'CJ1'
      DisplayFormat = '0.00'
    end
    object RS1FS1: TFloatField
      FieldName = 'FS1'
      DisplayFormat = '0.00'
    end
    object RS1CJ21: TFloatField
      FieldName = 'CJ21'
      DisplayFormat = '0.00'
    end
    object RS1CJ22: TFloatField
      FieldName = 'CJ22'
      DisplayFormat = '0.00'
    end
    object RS1CJ2: TFloatField
      FieldName = 'CJ2'
      DisplayFormat = '0.00'
    end
    object RS1FS2: TFloatField
      FieldName = 'FS2'
      DisplayFormat = '0.00'
    end
    object RS1ZF: TFloatField
      FieldName = 'ZF'
      DisplayFormat = '0.0'
    end
    object RS1flag: TIntegerField
      FieldName = 'flag'
    end
  end
  object WORKRS: TADOQuery
    Connection = CONN
    Parameters = <>
    Left = 368
    Top = 448
  end
  object SCORERS: TADOQuery
    Connection = CONN
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM CJPD')
    Left = 312
    Top = 448
    object SCORERSkslb: TSmallintField
      FieldName = 'kslb'
    end
    object SCORERScj: TFloatField
      FieldName = 'cj'
      DisplayFormat = '.00'
    end
    object SCORERSscore: TFloatField
      FieldName = 'score'
    end
    object SCORERSsex: TSmallintField
      FieldName = 'sex'
    end
  end
  object DS: TDataSource
    AutoEdit = False
    DataSet = RS1
    Left = 472
    Top = 448
  end
end
