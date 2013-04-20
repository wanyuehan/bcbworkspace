object dm: Tdm
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  Height = 150
  Width = 215
  object GRIDDS: TDataSource
    DataSet = RS
    Left = 32
    Top = 16
  end
  object RS: TADOTable
    Connection = conn
    CursorType = ctStatic
    TableName = 'lhscore'
    Left = 112
    Top = 16
    object RSFXM: TWideStringField
      FieldName = 'FXM'
      Size = 8
    end
    object RSFBMDDM: TWideStringField
      FieldName = 'FBMDDM'
      Size = 4
    end
    object RSFBZ: TWideStringField
      FieldName = 'FBZ'
      Size = 254
    end
    object RSFLHJSH: TWideStringField
      FieldName = 'FLHJSH'
      Size = 14
    end
    object RSFWL1: TFloatField
      FieldName = 'FWL1'
    end
    object RSFWL2: TFloatField
      FieldName = 'FWL2'
    end
    object RSFWL: TFloatField
      FieldName = 'FWL'
    end
    object RSFHX1: TFloatField
      FieldName = 'FHX1'
    end
    object RSFHX2: TFloatField
      FieldName = 'FHX2'
    end
    object RSFHX: TFloatField
      FieldName = 'FHX'
    end
    object RSFBMDMC: TWideStringField
      FieldName = 'FBMDMC'
      Size = 40
    end
    object RSFZKH: TWideStringField
      FieldName = 'FZKH'
      Size = 12
    end
    object RSfkddm: TWideStringField
      FieldName = 'fkddm'
      Size = 2
    end
    object RSfsjdm: TWideStringField
      FieldName = 'fsjdm'
      Size = 2
    end
    object RSfccdm: TWideStringField
      FieldName = 'fccdm'
      Size = 2
    end
    object RSfzwdm: TWideStringField
      FieldName = 'fzwdm'
      Size = 2
    end
  end
  object QRY: TADOQuery
    Connection = conn
    Parameters = <>
    Left = 160
    Top = 16
  end
  object conn: TADOConnection
    Connected = True
    ConnectionString = 'file name=connection.udl'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 72
    Top = 24
  end
end
