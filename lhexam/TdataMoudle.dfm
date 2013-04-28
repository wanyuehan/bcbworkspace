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
  object QRY: TADOQuery
    Connection = conn
    Parameters = <>
    Left = 160
    Top = 16
  end
  object conn: TADOConnection
    ConnectionString = 'FILE NAME=.\connection.udl'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 72
    Top = 16
  end
  object RS: TADOTable
    Connection = conn
    CursorType = ctStatic
    TableName = 'lhresault'
    Left = 112
    Top = 16
    object RSFZKH: TWideStringField
      FieldName = 'FZKH'
      Size = 12
    end
    object RSFXM: TWideStringField
      FieldName = 'FXM'
      Size = 8
    end
    object RSFLHJSH: TWideStringField
      FieldName = 'FLHJSH'
      Size = 14
    end
    object RSFWL1: TBCDField
      FieldName = 'FWL1'
      DisplayFormat = '00.00'
      EditFormat = '00.00'
      MaxValue = 10.000000000000000000
      Precision = 18
      Size = 2
    end
    object RSFWL2: TBCDField
      FieldName = 'FWL2'
      DisplayFormat = '00.00'
      EditFormat = '00.00'
      MaxValue = 10.000000000000000000
      Precision = 18
      Size = 2
    end
    object RSFWL: TBCDField
      FieldName = 'FWL'
      DisplayFormat = '00.00'
      EditFormat = '00.00'
      MaxValue = 10.000000000000000000
      Precision = 18
      Size = 2
    end
    object RSFHX1: TBCDField
      FieldName = 'FHX1'
      DisplayFormat = '00.00'
      EditFormat = '00.00'
      MaxValue = 10.000000000000000000
      Precision = 18
      Size = 2
    end
    object RSFHX2: TBCDField
      FieldName = 'FHX2'
      DisplayFormat = '00.00'
      EditFormat = '00.00'
      MaxValue = 10.000000000000000000
      Precision = 18
      Size = 2
    end
    object RSFHX: TBCDField
      FieldName = 'FHX'
      DisplayFormat = '00.00'
      EditFormat = '00.00'
      MaxValue = 10.000000000000000000
      Precision = 18
      Size = 2
    end
    object RSflag: TSmallintField
      FieldName = 'flag'
    end
    object RSkddm: TStringField
      FieldName = 'kddm'
      FixedChar = True
      Size = 4
    end
    object RSkcdm: TStringField
      FieldName = 'kcdm'
      FixedChar = True
      Size = 2
    end
    object RSzwh: TStringField
      FieldName = 'zwh'
      FixedChar = True
      Size = 2
    end
  end
end
