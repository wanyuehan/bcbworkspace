object MainFrm: TMainFrm
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = '2013'#24180#21021#20013#21319#23398#29702#21270#23454#39564#32771#35797#25104#32489#24405#20837#31995#32479
  ClientHeight = 485
  ClientWidth = 876
  Color = clBtnFace
  Font.Charset = GB2312_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 876
    Height = 41
    Align = alTop
    BevelOuter = bvLowered
    TabOrder = 0
    object Label1: TLabel
      Left = 24
      Top = 12
      Width = 65
      Height = 16
      Caption = #32771#28857#21517#31216':'
    end
    object Label3: TLabel
      Left = 533
      Top = 12
      Width = 75
      Height = 16
      Caption = #32771#35797#22330#27425#65306
    end
    object cbKD: TComboBox
      Left = 95
      Top = 9
      Width = 418
      Height = 24
      Style = csDropDownList
      Ctl3D = True
      ItemIndex = 0
      ParentCtl3D = False
      TabOrder = 0
      Text = #35831#36873#25321#32771#28857
      Items.Strings = (
        #35831#36873#25321#32771#28857
        #22235#20013
        #20845#20013
        #19971#20013
        #20843#20013)
    end
    object meKC: TMaskEdit
      Left = 614
      Top = 9
      Width = 65
      Height = 24
      Alignment = taCenter
      EditMask = '!99;1;_'
      MaxLength = 2
      TabOrder = 1
      Text = '  '
      OnKeyPress = meKCKeyPress
    end
    object btEnter: TButton
      Left = 696
      Top = 10
      Width = 75
      Height = 25
      Caption = #30830' '#23450
      TabOrder = 2
      OnClick = btEnterClick
    end
    object btReset: TButton
      Left = 792
      Top = 9
      Width = 75
      Height = 25
      Caption = #37325' '#36755
      TabOrder = 3
      OnClick = btResetClick
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 41
    Width = 233
    Height = 444
    Align = alLeft
    BevelOuter = bvLowered
    TabOrder = 1
    object lbSubject: TLabel
      AlignWithMargins = True
      Left = 0
      Top = 16
      Width = 230
      Height = 16
      Alignment = taCenter
      AutoSize = False
      Caption = #24403#21069#36755#20837#31185#30446':'#12298'%s'#12299#31532' %d '#36718
      Font.Charset = GB2312_CHARSET
      Font.Color = clRed
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      Transparent = True
    end
    object Label5: TLabel
      Left = 80
      Top = 48
      Width = 60
      Height = 16
      Caption = #25104#32489#24405#20837
    end
    object meScore: TMaskEdit
      Left = 33
      Top = 88
      Width = 142
      Height = 48
      Alignment = taCenter
      DoubleBuffered = False
      EditMask = '!99.99;1;_'
      Font.Charset = GB2312_CHARSET
      Font.Color = clHotLight
      Font.Height = -33
      Font.Name = 'Tahoma'
      Font.Style = []
      MaxLength = 5
      ParentDoubleBuffered = False
      ParentFont = False
      TabOrder = 0
      Text = '  .  '
      OnChange = meScoreChange
      OnKeyPress = meScoreKeyPress
    end
    object btNext: TButton
      Left = 34
      Top = 238
      Width = 143
      Height = 41
      Caption = #36755#20837#19979#19968#20010
      TabOrder = 1
      OnClick = btNextClick
    end
    object btPrev: TButton
      Left = 34
      Top = 285
      Width = 142
      Height = 44
      Caption = #20462#25913#19978#19968#20010
      TabOrder = 2
    end
    object btSave: TButton
      Left = 34
      Top = 335
      Width = 142
      Height = 42
      Caption = #20445#23384#26412#32452#25968#25454
      TabOrder = 3
      OnClick = btSaveClick
    end
    object btCancel: TButton
      Left = 33
      Top = 383
      Width = 142
      Height = 42
      Caption = #21462#28040#26412#32452#25968#25454
      TabOrder = 4
      OnClick = btCancelClick
    end
    object btAnotherSubject: TButton
      Left = 34
      Top = 142
      Width = 141
      Height = 67
      Caption = #21478#22806#19968#38376#35838#31243
      TabOrder = 5
      OnClick = btAnotherSubjectClick
    end
  end
  object Panel3: TPanel
    Left = 233
    Top = 41
    Width = 643
    Height = 444
    Align = alClient
    BevelOuter = bvLowered
    TabOrder = 2
    object dbGrid: TDBGrid
      Left = 1
      Top = 1
      Width = 641
      Height = 401
      Align = alClient
      DataSource = dm.GRIDDS
      TabOrder = 0
      TitleFont.Charset = GB2312_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -13
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
      OnCellClick = dbGridCellClick
      Columns = <
        item
          Alignment = taCenter
          Color = clGradientActiveCaption
          Expanded = False
          FieldName = 'FLHJSH'
          Font.Charset = GB2312_CHARSET
          Font.Color = clActiveCaption
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ReadOnly = True
          Title.Alignment = taCenter
          Title.Caption = #29702#21270#21152#35797#21495
          Width = 120
          Visible = True
        end
        item
          Alignment = taCenter
          Color = clCream
          Expanded = False
          FieldName = 'FXM'
          Font.Charset = GB2312_CHARSET
          Font.Color = clHighlight
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ReadOnly = True
          Title.Alignment = taCenter
          Title.Caption = #22995#21517
          Width = 100
          Visible = True
        end
        item
          Color = clSkyBlue
          Expanded = False
          Font.Charset = GB2312_CHARSET
          Font.Color = clNavy
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          Title.Caption = '%s'#31532'%d'#36718#25104#32489
          Width = 156
          Visible = True
        end
        item
          Alignment = taCenter
          Color = clCream
          Expanded = False
          FieldName = 'FLHFLAG'
          Font.Charset = GB2312_CHARSET
          Font.Color = clHighlight
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          Title.Alignment = taCenter
          Title.Caption = #36873#32771#31867#22411
          Width = 222
          Visible = True
        end>
    end
    object pmsg: TPanel
      Left = 1
      Top = 402
      Width = 641
      Height = 41
      Align = alBottom
      BevelOuter = bvLowered
      Caption = '%s '#22312#32771#28857' %s '#21442#21152' '#31532' %d '#27425#32771#35797#30340#23398#29983#20849#26377' %d '#20154
      TabOrder = 1
    end
  end
end
