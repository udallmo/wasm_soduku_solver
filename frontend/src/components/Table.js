import React from 'react';
import { makeStyles } from '@material-ui/core/styles';
import Table from '@material-ui/core/Table';
import TableBody from '@material-ui/core/TableBody';
import TableCell from '@material-ui/core/TableCell';
import TableContainer from '@material-ui/core/TableContainer';
import TableRow from '@material-ui/core/TableRow';
import Paper from '@material-ui/core/Paper';
import '../App.css'

const useStyles = makeStyles({
  table: {
    minWidth: 650,
  },
});

export default function SimpleTable(props) { 
  return (
    <TableContainer style={{background: '#253746', width: '250px'}} component={Paper}>
      <Table>
        <TableBody>
          {props.grid.map((row) => (
            <TableRow>
              <TableCell align="right" style={{border: '2px solid #fafafa'}}> <div style={{color: '#fafafa',  textAlign:'center' }}>{row[0]}</div></TableCell>
              <TableCell align="right" style={{border: '2px solid #fafafa'}}> <div style={{color: '#fafafa',  textAlign:'center' }}>{row[1]}</div></TableCell>
              <TableCell align="right" style={{border: '2px solid #fafafa'}}> <div style={{color: '#fafafa',  textAlign:'center' }}>{row[2]}</div></TableCell>
              <TableCell align="right" style={{border: '2px solid #fafafa'}}> <div style={{color: '#fafafa',  textAlign:'center' }}>{row[3]}</div></TableCell>
            </TableRow>
          ))}
        </TableBody>
      </Table>
    </TableContainer>
  );
}