#pragma once

template <typename T>
class Singleton
{
public:
    static T& Instance()    //�̱���
    {
        static T instance;
        return instance;
    }

    Singleton(const Singleton&) = delete;   //���� �����ڸ� ����
    Singleton& operator=(const Singleton&) = delete;    //���� �����ڸ� ����

protected:
    Singleton() = default;  //�⺻ �����ڴ� �� �� ����. ��� protected�� ���������� �ܺο��� ������ �� ���� ����. = {}�� ����
    virtual ~Singleton() = default;
};