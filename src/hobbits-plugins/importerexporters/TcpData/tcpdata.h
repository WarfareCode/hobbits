#ifndef TCPDATA_H
#define TCPDATA_H

#include "parameterdelegateui.h"
#include "importexportinterface.h"

class TcpData : public QObject, ImporterExporterInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "hobbits.ImporterExporterInterface.TcpData")
    Q_INTERFACES(ImporterExporterInterface)

public:
    TcpData();

    ImporterExporterInterface* createDefaultImporterExporter() override;

    QString name() override;
    QString description() override;
    QStringList tags() override;

    bool canExport() override;
    bool canImport() override;

    virtual QSharedPointer<ParameterDelegate> importParameterDelegate() override;
    virtual QSharedPointer<ParameterDelegate> exportParameterDelegate() override;

    QSharedPointer<ImportResult> importBits(QJsonObject parameters,
                                            QSharedPointer<PluginActionProgress> progress) override;
    QSharedPointer<ExportResult> exportBits(QSharedPointer<const BitContainer> container,
                                            QJsonObject parameters,
                                            QSharedPointer<PluginActionProgress> progress) override;

private:
    QSharedPointer<ParameterDelegateUi> m_importDelegate;
    QSharedPointer<ParameterDelegateUi> m_exportDelegate;
};

#endif // TCPDATA_H
