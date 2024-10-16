
namespace lasd {

/* ************************************************************************** */

//RowNumber
template <typename Data>
inline ulong Matrix<Data>::RowNumber() const noexcept{
    return rownum;
}

/* ************************************************************************** */

//ColumnNumber
template <typename Data>
inline ulong Matrix<Data>::ColumnNumber()const noexcept{
    return colnum;
}

/* ************************************************************************** */

}
