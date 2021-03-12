//////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                              //
// Copyright (c) 2019 Tencent.com, Inc. All Rights Reserved                                     //
// Author: Aster Jian (asterjian@qq.com)                                                        //
//                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace utils
{
    /**
     * \brief ���뷽ʽ
     */
    enum class Alignment
    {
        Default,
        Left,
        Right,
    };

    /**
     * \brief �ж���
     */
    struct Column
    {
        /**
         * \brief
         */
        Column(const std::string& name);

        /**
         * \brief ��������
         */
        Column& SetName(const std::string& name);

        /**
         * \brief ���þ��ȣ�С����λ����
         */
        Column& SetPrecision(int precision);

        /**
         * \brief ���ðٷ���
         */
        Column& SetPercentage(bool percentage);

        /**
         * \brief �ֶ����ÿ�ȣ��벻Ҫ���ã��Զ����õĻ�ȽϺã�
         */
         // Column& SetWidth(int width);

        /**
         * \brief �ֶ����ö��뷽ʽ���벻Ҫ���ã��Զ����õĻ�ȽϺã�
         */
        // Column& SetAlignment(Alignment alignment);

        /**
         * \brief ��ӡ����
         */
        void Print(std::ostream& os) const;

        /**
         * \brief ��ӡ�ַ���
         */
        void Print(std::ostream& os, const std::string& value) const;

        /**
         * \brief
         */
        std::string name_;

        /**
         * \brief ���ȣ�С����λ����
         */
        int precision_{ 3 };

        /**
         * \brief �ٷ���
         */
        bool percentage_{ false };

        /**
         * \brief �ֶ����õĿ��
         */
        int setted_width_{ 0 };

        /**
         * \brief �Զ����õĿ��
         */
        int preferred_width_{ 0 };

        /**
         * \brief �ֶ����õĶ��뷽ʽ
         */
        Alignment setted_alignment_{ Alignment::Default };

        /**
         * \brief �Զ����õĶ��뷽ʽ
         */
        Alignment preferred_alignment_{ Alignment::Right };
    };

    /**
     * \brief �ж���
     */
    struct Row
    {
        /**
         * \brief ���캯��
         */
        Row(std::vector<Column>& columns);

        /**
         * \brief ��Ӳ�����ֵ
         */
        Row& AddBool(bool value);

        /**
         * \brief ���������ֵ
         */

        Row& AddInt(int value);

        /**
         * \brief ��Ӹ�����ֵ
         */
        Row& AddFloat(float value);

        /**
         * \brief ����ַ�����ֵ
         */
        Row& AddString(const std::string& value);

        /**
         * \brief ���е�������
         */
        std::vector<Column>& columns_;

        /**
         * \brief ����ַ��������ֵ
         */
        std::vector<std::string> values_;
    };

    /**
     * \brief �����
     */
    class Table
    {
    public:
        /**
         * \brief
         */
        Table() = default;

        /**
         * \brief
         */
        ~Table() = default;

        /**
         * \brief �����
         */
        Column& AddColumn(const std::string& name)
        {
            columns_.push_back(Column(name));
            return columns_.back();
        }

        /**
         * \brief �����
         */
        Row& AddRow()
        {
            rows_.push_back(Row(columns_));
            return rows_.back();
        }

        /**
         * \brief ��ӡ����
         */
        void Print(std::ostream& os = std::cout) const;

    private:
        /**
         * \brief ���Ʊ�ͷ
         */
        void PrintHeader(std::ostream& os) const;

        /**
         * \brief ���ƺ���
         */
        void PrintLine(std::ostream& os, char ch) const;

        /**
         * \brief ����һ��
         */
        void PrintRow(std::ostream& os, const Row& row) const;

        /**
         * \brief ��ͷ����Ϣ
         */
        std::vector<Column> columns_;

        /**
         * \brief ���ÿ������
         */
        std::vector<Row> rows_;
    };
}
 